#pragma once

#include <Windows.h>
#include <Wininet.h>
#include <random>
#include <math.h>
#include <iostream>
#include <string>
#include <vector>


std::vector<std::string> explorers = 
{ "https://mempool.space/", "https://etherscan.io/", "https://live.blockcypher.com/ltc/", "https://dogechain.info/", "https://tronscan.org/#/", "https://solscan.io/", "https://polygonscan.com/" };

namespace inet
{
    std::string read_url(std::string url);
    DWORD post_request(std::string url, std::string request, DWORD* code, std::string* response);
    bool webstatus_check(const std::string& szAddress, DWORD* pdwWebStat);
}


bool is_transaction_hash(std::string hash);
std::string get_address_from_trans_hash(std::string address);

std::vector<std::string> get_interacted_addresses(std::string address);
float get_biggest_transaction(std::string address);
float get_lowest_transaction(std::string address);
float get_max_balance(std::string address);

float get_marketplace_risk(std::string address);
float get_payment_risk(std::string address);
float get_wallet_risk(std::string address);
float get_exchange_risk(std::string address);
float get_gambling_risk(std::string address);
float get_other_risk(std::string address);

float calculate_risk(float marketplace_risk, float payment_risk, float wallet_risk, float exchange_risk, float gambling_risk, float other_risk);

float get_btc_aml(std::string address);
float get_eth_aml(std::string address);
float get_ltc_aml(std::string address);
float get_doge_aml(std::string address);
float get_tron_aml(std::string address);
float get_sol_aml(std::string address);
float get_polygon_aml(std::string address);

float get_aml(std::string address_or_hash, int type_id);
