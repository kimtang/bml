\l bml.q

"Helper Functions"

steps0:{ [x;y;z] x+z*til 1+`long$(y-x) % z }
steps1:{steps0 . x}

"Helper Distribution"

dnorm:.bml.dist[`normal;0f;1f]

"Beta Distribution"

(::)param:flip (`beta;0.5 5 1 2 2;0.5 1 3 2 5)

(::)d:(.bml.dist .) each param

(::)pdf:raze param{[x;y;z] flip `x`pdf`alpha`beta!(x;z),`$string 1_y }[x]'d .bml.pdf\:x:steps1 0.01 0.99 0.01

(::)cdf:raze param{[x;y;z] flip `x`cdf`alpha`beta!(x;z),`$string 1_y }[x]'d .bml.cdf\:x:steps1 0.01 0.99 0.01

(::)qq:raze param{[x;y;z] flip `x`qq`alpha`beta!(x;z),`$string 1_y }[x]'d .bml.quantile\:x:steps1 0.01 0.99 0.01
