
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

.bml.lib.defPath:`$.bt.print[":%bml%/qlib/bml/cpp/bml.def"] .import.repository.con;
.bml.lib.def:update fname:`${"." sv string x}'[flip(repo;nsp;orig)] from update repo:`${".",1_first "_" vs x}@'name,nsp:`${first 1_"_" vs x}@'name,name:`${"_" sv  2_"_" vs x}@'name,orig:`$name from {select from x where not null num} flip`name`num!("*j";";") 0: read0 .bml.lib.defPath
.bml.lib.dll:`$.bt.print[":%bml%/qlib/bml/cpp/bin/%os%/%type%/bml"] .import.repository.con,.bml.lib,.bt.md[`os] .z.o

{@[x`repo;x`nsp;:;](1#`)!(1#{})}@'key select by repo,nsp from .bml.lib.def;
{.[x`repo;x`nsp`name;:;].bml.lib.dll 2: x`orig`num }@'.bml.lib.def;

.bml.dist[`cdf]:{[dist;xi] if[-9h=type dist;dist:`long$dist]; .bml.dist.cdf0[dist;xi] }
.bml.dist[`cdf_comp]:{[dist;xi] if[-9h=type dist;dist:`long$dist]; .bml.dist.cdf_comp0[dist;xi] }
.bml.dist[`pdf]:{[dist;xi] if[-9h=type dist;dist:`long$dist]; .bml.dist.pdf0[dist;xi] }
.bml.dist[`quantile]:{[dist;xi] if[-9h=type dist;dist:`long$dist]; .bml.dist.quantile0[dist;xi] }
.bml.dist[`quantile_comp]:{[dist;xi] if[-9h=type dist;dist:`long$dist]; .bml.dist.quantile_comp0[dist;xi] }
.bml.dist[`hazard]:{[dist;xi] if[-9h=type dist;dist:`long$dist]; .bml.dist.hazard0[dist;xi] }
.bml.dist[`chf]:{[dist;xi] if[-9h=type dist;dist:`long$dist]; .bml.dist.chf0[dist;xi] }
.bml.dist[`mean]:{[dist] if[-9h=type dist;dist:`long$dist]; .bml.dist.mean0[dist] }
.bml.dist[`median]:{[dist] if[-9h=type dist;dist:`long$dist]; .bml.dist.median0[dist] }
.bml.dist[`mode]:{[dist] if[-9h=type dist;dist:`long$dist]; .bml.dist.mode0[dist] }
.bml.dist[`standard_deviation]:{[dist] if[-9h=type dist;dist:`long$dist]; .bml.dist.standard_deviation0[dist] }
.bml.dist[`variance]:{[dist] if[-9h=type dist;dist:`long$dist]; .bml.dist.variance0[dist] }
.bml.dist[`skewness]:{[dist] if[-9h=type dist;dist:`long$dist]; .bml.dist.skewness0[dist] }
.bml.dist[`kurtosis]:{[dist] if[-9h=type dist;dist:`long$dist]; .bml.dist.kurtosis0[dist] }

.bml.rand[`del]:{[dist] if[-9h=type dist;dist:`long$dist]; .bml.rand.del0 dist }
.bml.rand[`generate]:{[seed;dist;xi] if[-9h=type dist;dist:`long$dist];if[-9h=type seed;seed:`long$seed]; .bml.rand.generate0[seed;dist;xi] }
