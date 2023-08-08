Bindings for Wavefront Alignment
================

This is a minimal example of R bindings to WFA2-lib, a state of the art dynamic programming alignment library. 

### Install
```
remotes::install_github("traversc/WavefrontAlignR")
```

### Usage
```
library(WavefrontAlignR)
x <- c("ACGT", "ACAGT", "CGCATTGCA")
y <- c("GACTGC", "GCATTGC", "CAGTTGCAGT", "ACGCATTGCA")
edit_dist_matrix(x, y)
```


See: https://github.com/smarco/WFA2-lib
Based on commit: 931181d94c0cfc4f96322b5a92aeb77359c6af8d