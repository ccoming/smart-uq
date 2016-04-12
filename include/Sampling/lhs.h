/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
/*
------------Copyright (C) 2016 University of Strathclyde--------------
------------ e-mail: annalisa.riccardi@strath.ac.uk ------------------
------------ e-mail: carlos.ortega@strath.ac.uk ----------------------
--------- Author: Annalisa Riccardi and Carlos Ortega Absil ----------
*/

#ifndef LHS_H
#define LHS_H


#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "base_sampling.h"

using namespace std;

namespace smartuq{
namespace sampling{

    /**
     * @brief
     * @author annalisa.riccardi@strath.ac.uk
    */

    template <class T>
    class lhs : public base_sampling <T>
    {
        private:
            using base_sampling<T>::m_dim;
            using base_sampling<T>::m_name;

        public:

            /**
             * @brief lhs
             * @param dim
             * @param npoints
             */
            lhs(const unsigned int &dim, const unsigned int &npoints);

            /**
              * @brief ~lhs
              */
            ~lhs();

            /**
             * @brief
             *
             * Returns the next point in the sequence
             * @return an std::vector<T> containing the next point
             */
            std::vector<T> operator()() const;

            /**
             * @brief
             *
             * Returns the n-th point in the sequence
             * @param[in] n the point along the sequence to be returned
             * @return an std::vector<T> containing the n-th point
             */
            std::vector<T> operator()(const unsigned int &n) const;

        private:
            std::vector<T> latin_random (const unsigned int &dim_num, const unsigned int &point_num) const;
            unsigned int *perm_uniform (const unsigned int &n) const;

        private:
            unsigned int m_npoints;/// Number of points to generate in set
            mutable bool m_initialised;
            mutable std::vector<T> m_set;
            mutable unsigned int m_next;
    };

}}


#endif // LHS_H
