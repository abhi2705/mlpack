/*
 * =====================================================================================
 *
 *       Filename:  trainer.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/30/2011 12:59:43
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Rongzhou Shen (rshen), anticlockwise5@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#ifndef TRAINER_H
#define TRAINER_H

#include <vector>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/info_parser.hpp>
#include <mlpack/prior.hpp>
#include <mlpack/index.hpp>

using namespace std;
using namespace boost::property_tree;

namespace mlpack {
    template <typename T>
        class Trainer {
            public:
                virtual T train(DataIndexer &di, ptree config) = 0;

                virtual void set_heldout_data(EventSpace events) = 0;
        };
}

#endif
