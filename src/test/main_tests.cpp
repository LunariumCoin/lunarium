// Copyright (c) 2014 The Bitcoin Core developers
// Copyright (c) 2014-2015 The Dash developers
// Copyright (c) 2015-2017 The PIVX developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "primitives/transaction.h"
#include "main.h"

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(main_tests)

CAmount nMoneySupplyPoWEnd = 5200003 * COIN;

BOOST_AUTO_TEST_CASE(subsidy_limit_test)
{
    CAmount nSum = 0;
    for (int nHeight = 0; nHeight < 1; nHeight += 1) {
        /* premine in block 1 (5,200,000 XLN) */
        CAmount nSubsidy = GetBlockValue(nHeight);
        BOOST_CHECK(nSubsidy <= 17500000 * COIN);
        nSum += nSubsidy;
    }

    for (int nHeight = 1; nHeight < 3000; nHeight += 1) {
        /* PoW end (5,200,003 XLN) */
        CAmount nSubsidy = GetBlockValue(nHeight);
        BOOST_CHECK(nSubsidy <= 5200003 * COIN);
        nSum += nSubsidy;
    }

    BOOST_CHECK(nSum > 0 && nSum <= nMoneySupplyPoWEnd);

    for (int nHeight = 3000; nHeight < 30000; nHeight += 1) {
        /* PoS Phase 1 (swap period) */
        CAmount nSubsidy = GetBlockValue(nHeight);
        BOOST_CHECK(nSubsidy <= 0.001 * COIN);
        nSum += nSubsidy;
    }

    for (int nHeight = 30001; nHeight <= 555602; nHeight += 1) {
        /* PoS Phase 2 */
        CAmount nSubsidy = GetBlockValue(nHeight);
        BOOST_CHECK(nSubsidy <= 10 * COIN);
        nSum += nSubsidy;
    }

    for (int nHeight = 555603; nHeight <= 1081203; nHeight += 1) {
        /* PoS Phase 3 */
        CAmount nSubsidy = GetBlockValue(nHeight);
        BOOST_CHECK(nSubsidy <= 9 * COIN);
        nSum += nSubsidy;
    }

    for (int nHeight = 1081204; nHeight <= 1606804; nHeight += 1) {
        /* PoS Phase 4 */
        CAmount nSubsidy = GetBlockValue(nHeight);
        BOOST_CHECK(nSubsidy <= 8 * COIN);
        nSum += nSubsidy;
    }

    for (int nHeight = 1606805; nHeight <= 2132405; nHeight += 1) {
        /* PoS Phase 5 */
        CAmount nSubsidy = GetBlockValue(nHeight);
        BOOST_CHECK(nSubsidy <= 7 * COIN);
        nSum += nSubsidy;
    }

    for (int nHeight = 2132406; nHeight <= 2658006; nHeight += 1) {
        /* PoS Phase 6 */
        CAmount nSubsidy = GetBlockValue(nHeight);
        BOOST_CHECK(nSubsidy <= 6 * COIN);
        nSum += nSubsidy;
    }

    for (int nHeight = 2658007; nHeight <= 3183607; nHeight += 1) {
        /* PoS Phase 7 */
        CAmount nSubsidy = GetBlockValue(nHeight);
        BOOST_CHECK(nSubsidy <= 5 * COIN);
        nSum += nSubsidy;
    }

    for (int nHeight = 3183608; nHeight <= 3709208; nHeight += 1) {
        /* PoS Phase 5 */
        CAmount nSubsidy = GetBlockValue(nHeight);
        BOOST_CHECK(nSubsidy <= 4 * COIN);
        nSum += nSubsidy;
    }

    for (int nHeight = 3709209; nHeight <= 4000000; nHeight += 1) {
        /* PoS Phase 6 (Finale phase) */
        CAmount nSubsidy = GetBlockValue(nHeight);
        BOOST_CHECK(nSubsidy <= 3 * COIN);
        nSum += nSubsidy;
    }
}

BOOST_AUTO_TEST_SUITE_END()
