args:.Q.def[`name`port!("99.q";9065);].Q.opt .z.x

/ remove this line when using in production
/ 99.q:localhost:9065::
{ if[not x=0; @[x;"\\\\";()]]; value"\\p 9065"; } @[hopen;`:localhost:9065;0];

\l qlib.q
.import.require`bml`qml
 
(::)xi:.math.linspace[`num`endpoint`retstep!(50j;1b;0b);-10;10]

(::)mean:0f
(::)standard_deviation:2f

(::)normal:.bml.dist.normal[mean;standard_deviation] / create normal distribution with 0 mean 1 stddev
(::)yi:.bml.dist.cdf[normal;xi]


(::)rnorm:.bml.rand[`normal;0f;1f]
(::)seed:.bml.seed[`mt19937;1234]

(::)r:.bml.rand.generate[seed;rnorm] n:1000
(::)s:.bml.rand.generate[seed;rnorm] n

(::).bml.stat.mean r
(::).bml.stat.variance r
(::).bml.stat.skewness r
(::).bml.stat.kurtosis r
(::).bml.stat.first_four_moments r
(::).bml.stat.median r
(::).bml.stat.interquartile_range r
(::).bml.stat.gini_coefficient r

(::).bml.stat.covariance[r;s]
(::).bml.stat.means_and_covariance[r;s]
(::).bml.stat.correlation_coefficient[r;s]