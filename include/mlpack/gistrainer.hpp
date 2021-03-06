/*
 * =====================================================================================
 *
 *       Filename:  gistrainer.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/30/2011 20:05:45
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Rongzhou Shen (rshen), anticlockwise5@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef GISTRAINER_H
#define GISTRAINER_H

#include <iostream>
#include <vector>
#include <boost/property_tree/ptree.hpp>
#include <mlpack/trainer.hpp>
#include <mlpack/index.hpp>
#include <mlpack/model.hpp>
#include <mlpack/params.hpp>

using boost::property_tree::ptree;
using namespace std;

namespace mlpack {
    const double NEAR_ZERO = 0.01;

    typedef vector<vector<double> > Matrix;

    class GISTrainer : public Trainer<MaxentModel> {
        bool use_simple_smoothing;

        bool use_slack_param;

        bool use_gaussian_smoothing;

        double sigma;

        double smoothing_observation;

        double cf_observed_expect;

        double tolerance;

        int n_uniq_events;

        int n_preds;

        int n_outcomes;

        int cutoff;

        EventSpace contexts;

        vector<string> outcome_labels;

        vector<string> pred_labels;

        vector<int> pred_counts;

        vector<int> num_feats;

        vector<Parameters> params;

        vector<Parameters> model_expects;

        vector<Parameters> observed_expects;

        Prior *prior;

        MaxentParameters *eval_params;

        public:
        GISTrainer() {
            use_simple_smoothing = false;
            use_slack_param = false;
            use_gaussian_smoothing = false;
            sigma = 2.0;
            smoothing_observation = 0.1;
            tolerance = 0.0001;
            prior = NULL;
        }

        MaxentModel train(DataIndexer &di, ptree config);

        void set_heldout_data(EventSpace events);

        private:
        void update(Parameters *p, vector<int> outcomes, int n_active_outcomes) {
            p->outcomes = outcomes;
            vector<double> params(n_active_outcomes);
            p->params = params;
        }

        void find_params(long iterations, int corr_constant);
        double next_iteration(int corr_constant);
    };
}

#endif
