/************************************************************
 *
 *  OTServer.hpp
 *
 */

/************************************************************
 -----BEGIN PGP SIGNED MESSAGE-----
 Hash: SHA1

 *                 OPEN TRANSACTIONS
 *
 *       Financial Cryptography and Digital Cash
 *       Library, Protocol, API, Server, CLI, GUI
 *
 *       -- Anonymous Numbered Accounts.
 *       -- Untraceable Digital Cash.
 *       -- Triple-Signed Receipts.
 *       -- Cheques, Vouchers, Transfers, Inboxes.
 *       -- Basket Currencies, Markets, Payment Plans.
 *       -- Signed, XML, Ricardian-style Contracts.
 *       -- Scripted smart contracts.
 *
 *  Copyright (C) 2010-2013 by "Fellow Traveler" (A pseudonym)
 *
 *  EMAIL:
 *  FellowTraveler@rayservers.net
 *
 *  BITCOIN:  1NtTPVVjDsUfDWybS4BwvHpG2pdS9RnYyQ
 *
 *  KEY FINGERPRINT (PGP Key in license file):
 *  9DD5 90EB 9292 4B48 0484  7910 0308 00ED F951 BB8E
 *
 *  OFFICIAL PROJECT WIKI(s):
 *  https://github.com/FellowTraveler/Moneychanger
 *  https://github.com/FellowTraveler/Open-Transactions/wiki
 *
 *  WEBSITE:
 *  http://www.OpenTransactions.org/
 *
 *  Components and licensing:
 *   -- Moneychanger..A Java client GUI.....LICENSE:.....GPLv3
 *   -- otlib.........A class library.......LICENSE:...LAGPLv3
 *   -- otapi.........A client API..........LICENSE:...LAGPLv3
 *   -- opentxs/ot....Command-line client...LICENSE:...LAGPLv3
 *   -- otserver......Server Application....LICENSE:....AGPLv3
 *  Github.com/FellowTraveler/Open-Transactions/wiki/Components
 *
 *  All of the above OT components were designed and written by
 *  Fellow Traveler, with the exception of Moneychanger, which
 *  was contracted out to Vicky C (bitcointrader4@gmail.com).
 *  The open-source community has since actively contributed.
 *
 *  -----------------------------------------------------
 *
 *   LICENSE:
 *   This program is free software: you can redistribute it
 *   and/or modify it under the terms of the GNU Affero
 *   General Public License as published by the Free Software
 *   Foundation, either version 3 of the License, or (at your
 *   option) any later version.
 *
 *   ADDITIONAL PERMISSION under the GNU Affero GPL version 3
 *   section 7: (This paragraph applies only to the LAGPLv3
 *   components listed above.) If you modify this Program, or
 *   any covered work, by linking or combining it with other
 *   code, such other code is not for that reason alone subject
 *   to any of the requirements of the GNU Affero GPL version 3.
 *   (==> This means if you are only using the OT API, then you
 *   don't have to open-source your code--only your changes to
 *   Open-Transactions itself must be open source. Similar to
 *   LGPLv3, except it applies to software-as-a-service, not
 *   just to distributing binaries.)
 *
 *   Extra WAIVER for OpenSSL, Lucre, and all other libraries
 *   used by Open Transactions: This program is released under
 *   the AGPL with the additional exemption that compiling,
 *   linking, and/or using OpenSSL is allowed. The same is true
 *   for any other open source libraries included in this
 *   project: complete waiver from the AGPL is hereby granted to
 *   compile, link, and/or use them with Open-Transactions,
 *   according to their own terms, as long as the rest of the
 *   Open-Transactions terms remain respected, with regard to
 *   the Open-Transactions code itself.
 *
 *   Lucre License:
 *   This code is also "dual-license", meaning that Ben Lau-
 *   rie's license must also be included and respected, since
 *   the code for Lucre is also included with Open Transactions.
 *   See Open-Transactions/src/otlib/lucre/LUCRE_LICENSE.txt
 *   The Laurie requirements are light, but if there is any
 *   problem with his license, simply remove the Lucre code.
 *   Although there are no other blind token algorithms in Open
 *   Transactions (yet. credlib is coming), the other functions
 *   will continue to operate.
 *   See Lucre on Github:  https://github.com/benlaurie/lucre
 *   -----------------------------------------------------
 *   You should have received a copy of the GNU Affero General
 *   Public License along with this program.  If not, see:
 *   http://www.gnu.org/licenses/
 *
 *   If you would like to use this software outside of the free
 *   software license, please contact FellowTraveler.
 *   (Unfortunately many will run anonymously and untraceably,
 *   so who could really stop them?)
 *
 *   DISCLAIMER:
 *   This program is distributed in the hope that it will be
 *   useful, but WITHOUT ANY WARRANTY; without even the implied
 *   warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 *   PURPOSE.  See the GNU Affero General Public License for
 *   more details.

 -----BEGIN PGP SIGNATURE-----
 Version: GnuPG v1.4.9 (Darwin)

 iQIcBAEBAgAGBQJRSsfJAAoJEAMIAO35UbuOQT8P/RJbka8etf7wbxdHQNAY+2cC
 vDf8J3X8VI+pwMqv6wgTVy17venMZJa4I4ikXD/MRyWV1XbTG0mBXk/7AZk7Rexk
 KTvL/U1kWiez6+8XXLye+k2JNM6v7eej8xMrqEcO0ZArh/DsLoIn1y8p8qjBI7+m
 aE7lhstDiD0z8mwRRLKFLN2IH5rAFaZZUvj5ERJaoYUKdn4c+RcQVei2YOl4T0FU
 LWND3YLoH8naqJXkaOKEN4UfJINCwxhe5Ke9wyfLWLUO7NamRkWD2T7CJ0xocnD1
 sjAzlVGNgaFDRflfIF4QhBx1Ddl6wwhJfw+d08bjqblSq8aXDkmFA7HeunSFKkdn
 oIEOEgyj+veuOMRJC5pnBJ9vV+7qRdDKQWaCKotynt4sWJDGQ9kWGWm74SsNaduN
 TPMyr9kNmGsfR69Q2Zq/FLcLX/j8ESxU+HYUB4vaARw2xEOu2xwDDv6jt0j3Vqsg
 x7rWv4S/Eh18FDNDkVRChiNoOIilLYLL6c38uMf1pnItBuxP3uhgY6COm59kVaRh
 nyGTYCDYD2TK+fI9o89F1297uDCwEJ62U0Q7iTDp5QuXCoxkPfv8/kX6lS6T3y9G
 M9mqIoLbIQ1EDntFv7/t6fUTS2+46uCrdZWbQ5RjYXdrzjij02nDmJAm2BngnZvd
 kamH0Y/n11lCvo1oQxM+
 =uSzz
 -----END PGP SIGNATURE-----
**************************************************************/

#ifndef __OT_SERVER_HPP__
#define __OT_SERVER_HPP__

#include "Transactor.hpp"
#include "MainFile.hpp"
#include "UserCommandProcessor.hpp"
#include <opentxs/core/OTCommon.hpp>
#include <opentxs/core/OTCron.hpp>
#include <opentxs/core/OTPseudonym.hpp>
#include <opentxs/core/OTTransaction.hpp>
#include <string>
#include <map>
#include <cstddef>

namespace opentxs
{

class OTAccount;
class OTAssetContract;
class ClientConnection;
class OTIdentifier;
class OTMessage;
class OTMint;
class OTPayment;
class OTServerContract;

class OTServer
{
    friend class Transactor;
    friend class MessageProcessor;
    friend class UserCommandProcessor;
    friend class MainFile;
    friend class AcctFunctor_PayDividend;

public:
    OTServer();
    ~OTServer();

    void Init(bool readOnly = false);

    bool IsFlaggedForShutdown() const;

    bool GetConnectInfo(OTString& hostname, int32_t& port);

    const OTPseudonym& GetServerNym() const;

    void ActivateCron();
    void ProcessCron();

    bool SendInstrumentToNym(const OTIdentifier& serverId,
                             const OTIdentifier& senderUserId,
                             const OTIdentifier& recipientUserId,
                             OTMessage* msg = nullptr,
                             const OTPayment* payment = nullptr,
                             const char* command = nullptr);

private:
    // Note: SendInstrumentToNym and SendMessageToNym CALL THIS.
    // They are higher-level, this is lower-level.
    bool DropMessageToNymbox(const OTIdentifier& serverId,
                             const OTIdentifier& senderUserId,
                             const OTIdentifier& recipientUserId,
                             OTTransaction::transactionType transactionType,
                             OTMessage* msg = nullptr,
                             const OTString* messageString = nullptr,
                             const char* command = nullptr);

    // Each asset contract has its own series of Mints
    OTMint* GetMint(const OTIdentifier& assetTypeId, int32_t seriesCount);

    // If the server receives a notarizeTransactions command, it will be
    // accompanied by a payload containing a ledger to be notarized.
    // UserCmdNotarizeTransactions will loop through that ledger,
    // and for each transaction within, it calls THIS method.
    void NotarizeTransaction(OTPseudonym& nym, OTTransaction& tranIn,
                             OTTransaction& tranOut, bool& outSuccess);
    void NotarizeTransfer(OTPseudonym& nym, OTAccount& fromAccount,
                          OTTransaction& tranIn, OTTransaction& tranOut,
                          bool& outSuccess);
    void NotarizeDeposit(OTPseudonym& nym, OTAccount& account,
                         OTTransaction& tranIn, OTTransaction& tranOut,
                         bool& outSuccess);
    void NotarizeWithdrawal(OTPseudonym& nym, OTAccount& account,
                            OTTransaction& tranIn, OTTransaction& tranOut,
                            bool& outSuccess);
    void NotarizeProcessInbox(OTPseudonym& nym, OTAccount& account,
                              OTTransaction& tranIn, OTTransaction& tranOut,
                              bool& outSuccess);
    void NotarizeProcessNymbox(OTPseudonym& nym, OTTransaction& tranIn,
                               OTTransaction& tranOut, bool& outSuccess);
    void NotarizeMarketOffer(OTPseudonym& nym, OTAccount& assetAccount,
                             OTTransaction& tranIn, OTTransaction& tranOut,
                             bool& outSuccess);
    void NotarizePaymentPlan(OTPseudonym& nym, OTAccount& depositorAccount,
                             OTTransaction& tranIn, OTTransaction& tranOut,
                             bool& outSuccess);
    void NotarizeSmartContract(OTPseudonym& nym, OTAccount& activatingAccount,
                               OTTransaction& tranIn, OTTransaction& tranOut,
                               bool& outSuccess);
    void NotarizeCancelCronItem(OTPseudonym& nym, OTAccount& assetAccount,
                                OTTransaction& tranIn, OTTransaction& tranOut,
                                bool& outSuccess);
    void NotarizeExchangeBasket(OTPseudonym& nym, OTAccount& sourceAccount,
                                OTTransaction& tranIn, OTTransaction& tranOut,
                                bool& outSuccess);
    void NotarizePayDividend(OTPseudonym& nym, OTAccount& account,
                             OTTransaction& tranIn, OTTransaction& tranOut,
                             bool& outSuccess);

private:
    // Why does the map of mints use multimap instead of map?
    // Because there might be multiple valid mints for the same asset type.
    // Perhaps I am redeeming tokens from the previous series, which have not
    // yet expired.
    // Only tokens from the new series are being issued today, but tokens from
    // the previous series are still good until their own expiration date, which
    // is coming up soon.
    // Therefore the server manages different mints for the same asset type, and
    // since the asset type is the key in the multimap, we don't want to
    // accidentally remove one from the list every time another is added. Thus
    // multimap is employed.
    typedef std::multimap<std::string, OTMint*> MintsMap;

private:
    MainFile mainFile_;
    Transactor transactor_;
    UserCommandProcessor userCommandProcessor_;

    OTString m_strWalletFilename;
    OTString m_strConfigFilename;
    OTString m_strLogFilename;
    // Used at least for whether or not to write to the PID.
    bool m_bReadOnly;
    // If the server wants to be shut down, it can set
    // this flag so the caller knows to do so.
    bool m_bShutdownFlag;

    OTString m_strVersion;
    // A hash of the server contract
    OTString m_strServerID;
    // A hash of the public key that signed the server contract
    OTString m_strServerUserID;
    // This is the server's own contract, containing its public key and
    // connect info.
    OTServerContract* m_pServerContract;

    OTPseudonym m_nymServer;

    // The mints for each asset type.
    MintsMap m_mapMints;

    OTCron m_Cron; // This is where re-occurring and expiring tasks go.
};

} // namespace opentxs

#endif // __OT_SERVER_HPP__
