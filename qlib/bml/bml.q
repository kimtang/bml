
d)lib bml.bml 
 Library for working with the os
 q).import.module`bml 
 q).import.module`bml.bml
 q).import.module"%bml%/qlib/bml/bml.q"

.bml.summary:{ raze {([]mode:x;fnc:key .bml x) }@'`seed`rnd`dist} 

d)fnc bml.bml.summary 
 Give a summary of this function
 q) .bml.summary[] 

if[not`.bml.lib.type~key`.bml.lib.type;.bml.lib.type:`Release];  / default is release


.bml.lib.path:`$.bt.print[":%bml%/qlib/bml/cpp/bin/%os%/%type%/bml"] .import.repository.con,.bml.lib,.bt.md[`os] .z.o
/ .bml.lib.path:`$.bt.print[":%bml%/qlib/bml/cpp/cmake-build-release/bml"] .import.repository.con,.bt.md[`os] .z.o


.bml.seed:()!()
.bml.seed[`minstd_rand0]: .bml.lib.path 2: (`minstd_rand0;1)
.bml.seed[`minstd_rand]: .bml.lib.path 2: (`minstd_rand;1)
.bml.seed[`rand48]: .bml.lib.path 2: (`rand48;1)
.bml.seed[`ecuyer1988]: .bml.lib.path 2: (`ecuyer1988;1)
.bml.seed[`knuth_b]: .bml.lib.path 2: (`knuth_b;1)
.bml.seed[`kreutzer1986]: .bml.lib.path 2: (`kreutzer1986;1)
.bml.seed[`taus88]: .bml.lib.path 2: (`taus88;1)
.bml.seed[`hellekalek1995]: .bml.lib.path 2: (`hellekalek1995;1)
.bml.seed[`mt11213b]: .bml.lib.path 2: (`mt11213b;1)
.bml.seed[`mt19937]: .bml.lib.path 2: (`mt19937;1)
.bml.seed[`mt19937_64]: .bml.lib.path 2: (`mt19937_64;1)
.bml.seed[`lagged_fibonacci607]: .bml.lib.path 2: (`lagged_fibonacci607;1)
.bml.seed[`lagged_fibonacci1279]: .bml.lib.path 2: (`lagged_fibonacci1279;1)
.bml.seed[`lagged_fibonacci2281]: .bml.lib.path 2: (`lagged_fibonacci2281;1)
.bml.seed[`lagged_fibonacci3217]: .bml.lib.path 2: (`lagged_fibonacci3217;1)
.bml.seed[`lagged_fibonacci4423]: .bml.lib.path 2: (`lagged_fibonacci4423;1)
.bml.seed[`lagged_fibonacci9689]: .bml.lib.path 2: (`lagged_fibonacci9689;1)
.bml.seed[`lagged_fibonacci19937]: .bml.lib.path 2: (`lagged_fibonacci19937;1)
.bml.seed[`lagged_fibonacci23209]: .bml.lib.path 2: (`lagged_fibonacci23209;1)
.bml.seed[`lagged_fibonacci44497]: .bml.lib.path 2: (`lagged_fibonacci44497;1)
.bml.seed[`ranlux3]: .bml.lib.path 2: (`ranlux3;1)
.bml.seed[`ranlux4]: .bml.lib.path 2: (`ranlux4;1)
.bml.seed[`ranlux64_3]: .bml.lib.path 2: (`ranlux64_3;1)
.bml.seed[`ranlux64_4]: .bml.lib.path 2: (`ranlux64_4;1)
.bml.seed[`ranlux3_01]: .bml.lib.path 2: (`ranlux3_01;1)
.bml.seed[`ranlux4_01]: .bml.lib.path 2: (`ranlux4_01;1)
.bml.seed[`ranlux64_3_01]: .bml.lib.path 2: (`ranlux64_3_01;1)
.bml.seed[`ranlux64_4_01]: .bml.lib.path 2: (`ranlux64_4_01;1)
.bml.seed[`ranlux24]: .bml.lib.path 2: (`ranlux24;1)
.bml.seed[`ranlux48]: .bml.lib.path 2: (`ranlux48;1)


.bml.rnd:()!()

.bml.rnd[`bernoulli]: .bml.lib.path 2: (`rbernoulli_distribution;1)
.bml.rnd[`beta]: .bml.lib.path 2: (`rbeta_distribution;2)
.bml.rnd[`binomial]: .bml.lib.path 2: (`rbinomial_distribution;2)
.bml.rnd[`cauchy]: .bml.lib.path 2: (`rcauchy_distribution;2)
.bml.rnd[`chi_squared]: .bml.lib.path 2: (`rchi_squared_distribution;1)
.bml.rnd[`exponential]: .bml.lib.path 2: (`rexponential_distribution;1)
.bml.rnd[`extreme_value]: .bml.lib.path 2: (`rextreme_value_distribution;2)
.bml.rnd[`fisher_f]: .bml.lib.path 2: (`rfisher_f_distribution;2)
.bml.rnd[`gamma]: .bml.lib.path 2: (`rgamma_distribution;2)
.bml.rnd[`geometric]: .bml.lib.path 2: (`rgeometric_distribution;1)
.bml.rnd[`laplace]: .bml.lib.path 2: (`rlaplace_distribution;2)
.bml.rnd[`lognormal]: .bml.lib.path 2: (`rlognormal_distribution;2)
.bml.rnd[`negative_binomial]: .bml.lib.path 2: (`rnegative_binomial_distribution;2)
.bml.rnd[`non_central_chi_squared]: .bml.lib.path 2: (`rnon_central_chi_squared_distribution;2)
.bml.rnd[`normal]: .bml.lib.path 2: (`rnormal_distribution;2)
.bml.rnd[`poisson]: .bml.lib.path 2: (`rpoisson_distribution;1)
.bml.rnd[`student_t]: .bml.lib.path 2: (`rstudent_t_distribution;1)
.bml.rnd[`triangle]: .bml.lib.path 2: (`rtriangle_distribution;2)
.bml.rnd[`uniform_int]: .bml.lib.path 2: (`runiform_int_distribution;2)
.bml.rnd[`uniform_real]: .bml.lib.path 2: (`runiform_real_distribution;2)
.bml.rnd[`uniform_smallint]: .bml.lib.path 2: (`runiform_smallint;2)
.bml.rnd[`weibull]: .bml.lib.path 2: (`rweibull_distribution;2)

.bml.dist:()!()

.bml.dist[`arcsine]: .bml.lib.path 2: (`darcsine_distribution;2)
.bml.dist[`bernoulli]: .bml.lib.path 2: (`dbernoulli_distribution;1)
.bml.dist[`beta]: .bml.lib.path 2: (`dbeta_distribution;2)
.bml.dist[`binomial]: .bml.lib.path 2: (`dbinomial_distribution;2)
.bml.dist[`cauchy]: .bml.lib.path 2: (`dcauchy_distribution;2)
.bml.dist[`chi_squared]: .bml.lib.path 2: (`dchi_squared_distribution;1)
.bml.dist[`exponential]: .bml.lib.path 2: (`dexponential_distribution;1)
.bml.dist[`extreme_value]: .bml.lib.path 2: (`dextreme_value_distribution;2)
.bml.dist[`fisher_f]: .bml.lib.path 2: (`dfisher_f_distribution;2)
.bml.dist[`gamma]: .bml.lib.path 2: (`dgamma_distribution;2)
.bml.dist[`geometric]: .bml.lib.path 2: (`dgeometric_distribution;1)
.bml.dist[`holtsmark]: .bml.lib.path 2: (`dholtsmark_distribution;2)
.bml.dist[`hypergeometric]: .bml.lib.path 2: (`dhypergeometric_distribution;3)
.bml.dist[`inverse_chi_squared]: .bml.lib.path 2: (`dinverse_chi_squared_distribution;2)
.bml.dist[`inverse_gamma]: .bml.lib.path 2: (`dinverse_gamma_distribution;2)
.bml.dist[`inverse_gaussian]: .bml.lib.path 2: (`dinverse_gaussian_distribution;2)
.bml.dist[`kolmogorov_smirnov]: .bml.lib.path 2: (`dkolmogorov_smirnov_distribution;2)
.bml.dist[`landau]: .bml.lib.path 2: (`dlandau_distribution;2)
.bml.dist[`laplace]: .bml.lib.path 2: (`dlaplace_distribution;2)
.bml.dist[`logistic]: .bml.lib.path 2: (`dlogistic_distribution;2)
.bml.dist[`lognormal]: .bml.lib.path 2: (`dlognormal_distribution;2)
.bml.dist[`mapairy]: .bml.lib.path 2: (`dmapairy_distribution;2)
.bml.dist[`negative_binomial]: .bml.lib.path 2: (`dnegative_binomial_distribution;2)
.bml.dist[`non_central_beta]: .bml.lib.path 2: (`dnon_central_beta_distribution;3)
.bml.dist[`non_central_chi_squared]: .bml.lib.path 2: (`dnon_central_chi_squared_distribution;2)
.bml.dist[`non_central_f]: .bml.lib.path 2: (`dnon_central_f_distribution;3)
.bml.dist[`non_central_t]: .bml.lib.path 2: (`dnon_central_t_distribution;2)
.bml.dist[`normal]: .bml.lib.path 2: (`dnormal_distribution;2)
.bml.dist[`pareto]: .bml.lib.path 2: (`dpareto_distribution;2)
.bml.dist[`poisson]: .bml.lib.path 2: (`dpoisson_distribution;1)
.bml.dist[`rayleigh]: .bml.lib.path 2: (`drayleigh_distribution;1)
.bml.dist[`saspoint5]: .bml.lib.path 2: (`dsaspoint5_distribution;2)
.bml.dist[`skew_normal]: .bml.lib.path 2: (`dskew_normal_distribution;3)
.bml.dist[`students_t]: .bml.lib.path 2: (`dstudents_t_distribution;1)
.bml.dist[`triangular]: .bml.lib.path 2: (`dtriangular_distribution;3)
.bml.dist[`uniform]: .bml.lib.path 2: (`duniform_distribution;2)
.bml.dist[`weibull]: .bml.lib.path 2: (`dweibull_distribution;2)


.bml.dot: .bml.lib.path 2: (`dot_;2)


.bml.cdf0: .bml.lib.path 2: (`cdf;2)
.bml.cdf:{[dist;xi] if[-9h=type dist;dist:`long$dist]; .bml.cdf0[dist;xi] }

.bml.cdf_comp0: .bml.lib.path 2: (`cdf_comp;2)
.bml.cdf_comp:{[dist;xi] if[-9h=type dist;dist:`long$dist]; .bml.cdf_comp0[dist;xi] }

.bml.pdf0: .bml.lib.path 2: (`pdf;2)
.bml.pdf:{[dist;xi] if[-9h=type dist;dist:`long$dist]; .bml.pdf0[dist;xi] }

.bml.quantile0: .bml.lib.path 2: (`quantile;2)
.bml.quantile:{[dist;xi] if[-9h=type dist;dist:`long$dist]; .bml.quantile0[dist;xi] }

.bml.quantile_comp0: .bml.lib.path 2: (`quantile_comp;2)
.bml.quantile_comp:{[dist;xi] if[-9h=type dist;dist:`long$dist]; .bml.quantile_comp0[dist;xi] }

.bml.hazard0: .bml.lib.path 2: (`hazard;2)
.bml.hazard:{[dist;xi] if[-9h=type dist;dist:`long$dist]; .bml.hazard0[dist;xi] }

.bml.chf0: .bml.lib.path 2: (`chf;2)
.bml.chf:{[dist;xi] if[-9h=type dist;dist:`long$dist]; .bml.chf0[dist;xi] }

.bml.mean0: .bml.lib.path 2: (`mean_;1)
.bml.mean:{[dist] if[-9h=type dist;dist:`long$dist]; .bml.mean0[dist] }

.bml.median0: .bml.lib.path 2: (`median_;1)
.bml.median:{[dist] if[-9h=type dist;dist:`long$dist]; .bml.median0[dist] }

.bml.mode0: .bml.lib.path 2: (`mode_;1)
.bml.mode:{[dist] if[-9h=type dist;dist:`long$dist]; .bml.mode0[dist] }

.bml.standard_deviation0: .bml.lib.path 2: (`standard_deviation_;1)
.bml.standard_deviation:{[dist] if[-9h=type dist;dist:`long$dist]; .bml.standard_deviation0[dist] }

.bml.variance0: .bml.lib.path 2: (`variance_;1)
.bml.variance:{[dist] if[-9h=type dist;dist:`long$dist]; .bml.variance0[dist] }

.bml.skewness0: .bml.lib.path 2: (`skewness_;1)
.bml.skewness:{[dist] if[-9h=type dist;dist:`long$dist]; .bml.skewness0[dist] }

.bml.kurtosis0: .bml.lib.path 2: (`kurtosis_;1)
.bml.kurtosis:{[dist] if[-9h=type dist;dist:`long$dist]; .bml.kurtosis0[dist] }

.bml.del0: .bml.lib.path 2: (`delete_;1)
.bml.del:{[dist] if[-9h=type dist;dist:`long$dist]; .bml.del0[dist] }

.bml.generate0: .bml.lib.path 2: (`generate;3)
.bml.generate:{[seed;dist;xi] if[-9h=type dist;dist:`long$dist];if[-9h=type seed;seed:`long$seed]; .bml.generate0[seed;dist;xi] }




