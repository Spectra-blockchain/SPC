// Copyright (c) 2020 The Spectra developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.
 
#include <amount.h>
#include <util.h>

/**
 * The number of blocks that both new and old MN collateral value will
 * be accepted, for smoother transition.
 */
const unsigned int COLLATERAL_TRANSITION_BLOCKS = 100;

/**
 * Determine the masternode collateral value based on block height
 */
CAmount CollateralRequired(int nHeight)
{
    if (nHeight >  500000) return   100000 * COIN;
    if (nHeight >  300000) return    50000 * COIN;
    if (nHeight >  200000) return    20000 * COIN;
    if (nHeight >  100000) return     2000 * COIN;
         
    return 1000 * COIN;
}


/**
 * Provide transition period for masternode collateral change to avoid
 * unneccessary issues to masternode operators for the amount of 
 * COLLATERAL_TRANSITION_BLOCKS blocks during the collateral change.
 */
bool IsValidCollateral(CAmount nAmountToCheck, int nHeight)
{
    return (
        nAmountToCheck == CollateralRequired(nHeight) || 
        nAmountToCheck == CollateralRequired(nHeight - floor(COLLATERAL_TRANSITION_BLOCKS / 2)) ||
        nAmountToCheck == CollateralRequired(nHeight + floor(COLLATERAL_TRANSITION_BLOCKS / 2))
        );
}
