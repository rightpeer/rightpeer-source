// Copyright (c) RightPeer Limited RightPeer
// RightPeer code distributed under the GPLv3 license, see COPYING file.

#ifndef RIGHTPEERFILTER_H
#define RIGHTPEERFILTER_H

#include "core/init.h"
#include "core/main.h"
#include "utils/util.h"
#include "utils/utilparse.h"
#include "rightpeer/rightpeer.h"
#include "json/json_spirit_value.h"
//#include "filters/filter.h"

#define MC_FLT_TYPE_BAD                    0xFFFFFFFF
#define MC_FLT_TYPE_TX                     0
#define MC_FLT_TYPE_STREAM                 1

#define MC_FLT_MAIN_NAME_TX                "filtertransaction"
#define MC_FLT_MAIN_NAME_STREAM            "filterstreamitem"

std::vector <uint160>  mc_FillRelevantFilterEntitities(const unsigned char *ptr, size_t value_size);

class mc_Filter;

typedef struct mc_RightPeerFilter
{
    std::vector <uint160> m_RelevantEntities;
    
    mc_EntityDetails m_Details;
    std::string m_CreateError;
    std::string m_MainName;
    std::string m_FilterCaption;
    uint32_t m_FilterType;
    int m_FilterCodeRow;
    uint160 m_FilterAddress;
    bool m_AlreadyUsed;
    
    mc_RightPeerFilter()
    {
        Zero();
    }
    
    ~mc_RightPeerFilter()
    {
        Destroy();
    }
    
    int Initialize(const unsigned char* short_txid);
    
    int Zero();
    int Destroy();   

    bool HasRelevantEntity(std::set <uint160>& sRelevantEntities);
    
} mc_RightPeerFilter;

typedef struct mc_RightPeerFilterParams
{
    int m_MaxShownData;
    int m_Compatibility;
    mc_RightPeerFilterParams()
    {
        Zero();
    }
    
    ~mc_RightPeerFilterParams()
    {
        Destroy();
    }
    
    int Zero();
    int Destroy();  
    int Init();
    int Close();
}mc_RightPeerFilterParams;

typedef struct mc_RightPeerFilterEngine
{
    std::vector <mc_RightPeerFilter> m_Filters;
    std::vector <std::vector <std::string>> m_CallbackNames;
    mc_Buffer *m_Workers;
    mc_Script *m_CodeLibrary;
    uint256 m_TxID;
    CTransaction m_Tx;
    int m_Vout;
    mc_RightPeerFilterParams m_Params;

    mc_RightPeerFilterEngine()
    {
        Zero();
    }
    
    ~mc_RightPeerFilterEngine()
    {
        Destroy();
    }
    
    int Initialize();
    void SetCallbackNames();
    int GetAcceptTimeout();
    int GetSendTimeout();
    int SetTimeout(int timeout);    
    int Add(const unsigned char* short_txid,int for_block);
    int Reset(int block,int for_block);
    int RunTxFilters(const CTransaction& tx,std::set <uint160>& sRelevantEntities,std::string &strResult,mc_RightPeerFilter **lppFilter,int *applied,bool only_once);            
    int RunStreamFilters(const CTransaction& tx,int vout, unsigned char *stream_short_txid,int block,int offset,std::string &strResult,mc_RightPeerFilter **lppFilter,int *applied);            
    int RunFilter(const CTransaction& tx,mc_Filter *filter,std::string &strResult);            
    int RunFilterWithCallbackLog(const CTransaction& tx,int vout,mc_Filter *filter,std::string &strResult, json_spirit::Array& callbacks);
    int NoStreamFilters();
    
    int Zero();
    int Destroy();   
    
} mc_RightPeerFilterEngine;

#endif /* RIGHTPEERFILTER_H */

