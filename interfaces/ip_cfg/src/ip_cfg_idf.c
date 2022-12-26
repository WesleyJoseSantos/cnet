/**
 * @file ip_cfg_idf.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-12-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "cnet_config.h"

#ifdef CNET_CONFIG_HARDWARE_ESP32_IDF

#include "ip_cfg.h"
#include "esp_netif.h"
#include "cnet_error.h"

int ip_cfg_set(void *interface, ip_cfg_t *cfg)
{
    esp_netif_t *netif = (esp_netif_t*)interface;
    esp_netif_ip_info_t ip_info;
    esp_netif_dns_info_t dns_info;

    switch (cfg->dhcp)
    {
    case IP_CFG_DHCP_MODE_CLIENT:
        esp_netif_dhcps_stop(netif);
        esp_netif_dhcpc_start(netif);
        break;
    case IP_CFG_DHCP_MODE_SERVER:
        esp_netif_dhcps_start(netif);
        esp_netif_dhcpc_stop(netif);
        break;
    case IP_CFG_DHCP_MODE_DISABLED:
        esp_netif_dhcps_stop(netif);
        esp_netif_dhcpc_stop(netif);
        break;
    default:
        break;
    }

    ip_info.ip.addr = esp_ip4addr_aton(cfg->ip);
    ip_info.netmask.addr = esp_ip4addr_aton(cfg->mask);
    ip_info.gw.addr = esp_ip4addr_aton(cfg->gateway);
    dns_info.ip.u_addr.ip4.addr = esp_ip4addr_aton(cfg->dns);

    CNET_ERROR_CHECK(esp_netif_set_ip_info(netif, &ip_info));
    CNET_ERROR_CHECK(esp_netif_set_dns_info(netif, ESP_NETIF_DNS_MAIN, &dns_info));
}

#endif // CNET_CONFIG_HARDWARE_ESP32_IDF