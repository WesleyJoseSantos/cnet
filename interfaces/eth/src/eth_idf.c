/**
 * @file eth_idf.c
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-12-25
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "cnet_config.h"

#ifdef CNET_CONFIG_HARDWARE_ESP32_IDF

#include "net_info.h"
#include "cnet_error.h"
#include "cnet_app.h"
#include "eth.h"


#include "esp_eth.h"
#include "esp_eth_mac.h"
#include "esp_netif.h"
#include "esp_event.h"

typedef struct eth_idf
{
    esp_eth_handle_t handle;
    eth_t eth;
    esp_netif_t *netif;
} eth_idf_t;

static void eth_event_handler(void *arg, esp_event_base_t event_base, int32_t event_id, void *event_data);

static eth_idf_t this;
static const char *TAG = "eth_idf";

int eth_init(void)
{
    return esp_event_handler_register(ETH_EVENT, ESP_EVENT_ANY_ID, &eth_event_handler, NULL);
}

int eth_start(eth_cfg_t *cfg)
{
    if (this.eth.status.started == false)
    {
        esp_netif_config_t netif_cfg = ESP_NETIF_DEFAULT_ETH();
        this.netif = esp_netif_new(&netif_cfg);

        eth_mac_config_t mac_config = ETH_MAC_DEFAULT_CONFIG();
        eth_phy_config_t phy_config = ETH_PHY_DEFAULT_CONFIG();

        phy_config.phy_addr = CNET_CONFIG_ETH_PHY_ADDR;
        phy_config.reset_gpio_num = CNET_CONFIG_ETH_PHY_RST_GPIO;

        eth_esp32_emac_config_t esp32_emac_config = ETH_ESP32_EMAC_DEFAULT_CONFIG();
        esp32_emac_config.smi_mdc_gpio_num = CNET_CONFIG_ETH_MDC_GPIO;
        esp32_emac_config.smi_mdio_gpio_num = CNET_CONFIG_ETH_MDIO_GPIO;

        esp_eth_mac_t *mac = esp_eth_mac_new_esp32(&esp32_emac_config, &mac_config);
        esp_eth_phy_t *phy = BOARD_ETH_PHY_NEW(phy_config);
        esp_eth_config_t eth_cfg = ETH_DEFAULT_CONFIG(mac, phy);

        CNET_ERROR_CHECK(esp_eth_driver_install(&eth_cfg, &this.handle));
        CNET_ERROR_CHECK(esp_netif_attach(this.netif, esp_eth_new_netif_glue(this.handle)));
    }

    if (this.eth.status.started == true)
    {
        this.eth.status.started = false;
        CNET_ERROR_CHECK(esp_eth_stop(this.handle));
    }

    CNET_ERROR_CHECK(esp_eth_start(this.handle));
    CNET_ERROR_CHECK(ip_cfg_set(this.netif, &cfg->ip_cfg));
}

int eth_stop(void)
{
    esp_eth_stop(this.handle);
}

int eth_get_status(net_status_t *status)
{
    *status = this.eth.status;
}

int eth_get_info(net_info_t *info)
{
    *info = this.eth.info;
}

static void eth_event_handler(void *arg, esp_event_base_t event_base, int32_t event_id, void *event_data)
{
    uint8_t mac_addr[6] = {0};
    switch (event_id)
    {
    case ETHERNET_EVENT_CONNECTED:
        ESP_LOGI(TAG, "Ethernet Link Up");
        break;
    case ETHERNET_EVENT_DISCONNECTED:
        ESP_LOGI(TAG, "Ethernet Link Down");
        this.eth.status.connected = false;
        this.eth.info.ip[0] = '\0';
        break;
    case ETHERNET_EVENT_START:
        ESP_LOGI(TAG, "Ethernet Started");
        this.eth.status.started = true;
        break;
    case ETHERNET_EVENT_STOP:
        ESP_LOGI(TAG, "Ethernet Stopped");
        this.eth.status.started = false;
        break;
    case IP_EVENT_ETH_GOT_IP:
    {
        ESP_LOGI(TAG, "IP_EVENT_ETH_GOT_IP");
        ip_event_got_ip_t *event = (ip_event_got_ip_t *)event_data;
        sprintf(this.eth.info.ip, IPSTR, IP2STR(&event->ip_info.ip));
        cnet_app_set_msg_event_bit(CNET_APP_MSG_ID_START);
        break;
    }
    default:
        break;
    }
}

#endif // CNET_CONFIG_HARDWARE_ESP32_IDF
