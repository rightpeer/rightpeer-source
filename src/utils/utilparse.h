// Copyright (c) RightPeer Limited RightPeer
// RightPeer code distributed under the GPLv3 license, see COPYING file.

#ifndef RIGHTPEERUTILS_H
#define	RIGHTPEERUTILS_H

#include "structs/base58.h"
#include "rightpeer/rightpeer.h"
#include "primitives/transaction.h"
#include "keys/key.h"
#include "core/main.h"

bool ExtractDestinationScriptValid(const CScript& scriptPubKey, CTxDestination& addressRet);
const unsigned char* GetAddressIDPtr(const CTxDestination& address);
bool HasPerOutputDataEntries(const CTxOut& txout,mc_Script *lpScript);
bool ParseRightpeerTxOutToBuffer(uint256 hash,const CTxOut& txout,mc_Buffer *amounts,mc_Script *lpScript,int *allowed,int *required,std::map<uint32_t, uint256>* mapSpecialEntity,std::string& strFailReason);
bool ParseRightpeerTxOutToBuffer(uint256 hash,const CTxOut& txout,mc_Buffer *amounts,mc_Script *lpScript,int *allowed,int *required,std::string& strFailReason);
bool CreateAssetBalanceList(const CTxOut& txout,mc_Buffer *amounts,mc_Script *lpScript,int *required);
bool CreateAssetBalanceList(const CTxOut& txout,mc_Buffer *amounts,mc_Script *lpScript);
void LogAssetTxOut(std::string message,uint256 hash,int index,unsigned char* assetrefbin,int64_t quantity);
bool AddressCanReceive(CTxDestination address);
bool FindFollowOnsInScript(const CScript& script1,mc_Buffer *amounts,mc_Script *lpScript);
int CheckRequiredPermissions(const CTxDestination& addressRet,int expected_allowed,std::map<uint32_t, uint256>* mapSpecialEntity,std::string* strFailReason);
bool mc_VerifyAssetPermissions(mc_Buffer *assets, std::vector<CTxDestination> addressRets, int required_permissions, uint32_t permission, std::string& reason);
bool mc_ExtractOutputAssetQuantities(mc_Buffer *assets,std::string& reason,bool with_followons);


#endif	/* RIGHTPEERUTILS_H */

