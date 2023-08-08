#include <Rcpp.h>
#include "bindings/cpp/WFAligner.hpp"
using namespace wfa;
using namespace Rcpp;

// [[Rcpp::export(rng = false)]]
IntegerMatrix edit_dist_matrix(const std::vector<std::string> & query, const std::vector<std::string> & target) {
    // Create a WFAligner
    WFAlignerEdit aligner(WFAligner::Score, WFAligner::MemoryHigh);
    // Create a matrix to store the results
    IntegerMatrix results(query.size(), target.size());
    int * results_ptr = INTEGER(results);
    // Loop over the sequences
    for(size_t j = 0; j < target.size(); ++j) {
        for(size_t i = 0; i < query.size(); ++i) {
            // Align the sequences
            aligner.alignEnd2End(query[i], target[j]);
            // Get the edit distance
            results_ptr[i + j*query.size()] = aligner.getAlignmentScore();
        }
    }
    return results;
}