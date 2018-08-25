// Copyright (c) 2011-2013 The Bitcoin Core developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

//
// Unit tests for block-chain checkpoints
//

#include "checkpoints.h"

#include "uint256.h"

#include <boost/test/unit_test.hpp>

using namespace std;

BOOST_AUTO_TEST_SUITE(Checkpoints_tests)

BOOST_AUTO_TEST_CASE(sanity)
{
    uint256 p3001 = uint256("0xd2bd76d2068dd66e0304b3b34924c9bbf00865087d8dbf55854f7ca2e255670b");
    uint256 p7474 = uint256("0x34847b79125d8907c6fb5abf04038b56b1bf7e84100740ee85202b8676bef204");
    BOOST_CHECK(Checkpoints::CheckBlock(3001, p3001));
    BOOST_CHECK(Checkpoints::CheckBlock(7474, p7474));


    // Wrong hashes at checkpoints should fail:
    BOOST_CHECK(!Checkpoints::CheckBlock(3001, p7474));
    BOOST_CHECK(!Checkpoints::CheckBlock(7474, p3001));

    // ... but any hash not at a checkpoint should succeed:
    BOOST_CHECK(Checkpoints::CheckBlock(3001+1, p7474));
    BOOST_CHECK(Checkpoints::CheckBlock(7474+1, p3001));

    int test = Checkpoints::GetTotalBlocksEstimate();

    BOOST_CHECK(Checkpoints::GetTotalBlocksEstimate() >= 10000);
}

BOOST_AUTO_TEST_SUITE_END()
