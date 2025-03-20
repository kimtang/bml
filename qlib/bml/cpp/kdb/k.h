
# define KXVER 3

# ifndef KX
# define KX
namespace kx{
	typedef const char* SS;
	typedef char*S,
				 C;
	typedef unsigned char G;
	typedef short H;
	typedef int I;
	typedef long long J;
	typedef float E;
	typedef double F;
	typedef void V;
# ifdef __cplusplus
extern"C"{
# endif
# if KXVER>=3
	typedef struct k0{
		signed char m,
					a,
					t;
		C u;
		I r;
		union{
			G g;
			H h;
			I i;
			J j;
			E e;
			F f;
			S s;
			struct k0*k;
			struct{
				J n;
				G G0[1];
			};};}*K;

	typedef struct{G g[16];}U;
	# define kx_kU(x) ((U*)kx_kG(x))
	# define kx_xU ((U*)kx_xG)
	extern K ku(U),
			 ktn(I,J),
			 kpn(S,J);
	# define kx_DO(n,x)	{J i=0,_i=(n);for(;i<_i;++i){x;}}
# else
	typedef struct k0{
		I r;
		H t,
		  u;
		union{
			G g;
			H h;
			I i;
			J j;
			E e;
			F f;
			S s;
			struct k0*k;
			struct{I n;G G0[1];};};}*K;
	extern K ktn(I,I),kpn(S,I);
	# define kx_DO(n,x)	{I i=0,_i=(n);for(;i<_i;++i){x;}}
# endif
# ifdef __cplusplus
}
# endif
//#include<string.h>
// vector accessors, e.g. kF(x)[i] for float&datetime
# define kx_kG(x)	((x)->G0)
# define kx_kC(x)	kx_kG(x)
# define kx_kH(x)	((H*)kx_kG(x))
# define kx_kI(x)	((I*)kx_kG(x))
# define kx_kJ(x)	((J*)kx_kG(x))
# define kx_kE(x)	((E*)kx_kG(x))
# define kx_kF(x)	((F*)kx_kG(x))
# define kx_kS(x)	((S*)kx_kG(x))
# define kx_kK(x)	((K*)kx_kG(x))

//      type bytes qtype     ctype  accessor
# define kx_KB 1  // 1 boolean   char   kG
# define kx_UU 2  // 16 guid     U      kU
# define kx_KG 4  // 1 byte      char   kG
# define kx_KH 5  // 2 short     short  kH
# define kx_KI 6  // 4 int       int    kI
# define kx_KJ 7  // 8 long      long   kJ
# define kx_KE 8  // 4 real      float  kE
# define kx_KF 9  // 8 float     double kF
# define kx_KC 10 // 1 char      char   kC
# define kx_KS 11 // * symbol    char*  kS

# define kx_KP 12 // 8 timestamp long   kJ (nanoseconds from 2000.01.01)
# define kx_KM 13 // 4 month     int    kI (months from 2000.01.01)
# define kx_KD 14 // 4 date      int    kI (days from 2000.01.01)

# define kx_KN 16 // 8 timespan  long   kJ (nanoseconds)
# define kx_KU 17 // 4 minute    int    kI
# define kx_KV 18 // 4 second    int    kI
# define kx_KT 19 // 4 time      int    kI (millisecond)

# define kx_KZ 15 // 8 datetime  double kF (DO NOT USE)

// table,dict
#define kx_XT 98 //   x->k is XD
#define kx_XD 99 //   kK(x)[0] is keys. kK(x)[1] is values.

# ifdef __cplusplus
extern"C"{
# endif
	extern I khpun(const SS,I,const SS,I),
			 khpu(const SS,I,const SS),
			 khp(const SS,I),
			 ymd(I,I,I),
			 dj(I);
	extern V r0(K),
			 sd0(I),
			 m9(),
			 kclose(I);
	extern S sn(SS,I),
			 ss(SS);
	extern K ktj(I,J),
			 ka(I),
			 kb(I),
			 kg(I),
			 kh(I),
			 ki(I),
			 kj(J),
			 ke(F),
			 kf(F),
			 kc(I),
			 ks(SS),
			 kd(I),
			 kz(F),
			 kt(I),
			 sd1(I,K(*)(I)),
			 dl(V*f,I),
			 knk(I,...),
			 kp(SS),
			 ja(K*,V*),
			 js(K*,SS),
			 jk(K*,K),
			 k(I,const SS,...),
			 xT(K),
			 xD(K,K),
			 ktd(K),
			 r1(K),
			 krr(SS),
			 orr(SS),
			 dot(K,K),
			 b9(I,K),
			 d9(K);
# ifdef __cplusplus 
}
# endif

// nulls(n?) and infinities(w?)
# define kx_nh ((I)0xFFFF8000)
# define kx_wh ((I)0x7FFF)
# define kx_ni ((I)0x80000000)
# define kx_wi ((I)0x7FFFFFFF)
# ifdef WIN32
	# define kx_nj ((J)0x8000000000000000)
	# define kx_wj ((J)0x7FFFFFFFFFFFFFFF)
	# define kx_nf (log(-1.0))
	# define kx_wf (-log(0.0))
	# define kx_isnan _isnan
	# define kx_finite _finite
	extern double log();
# else  
	# define kx_nj 0x8000000000000000LL
	# define kx_wj 0x7FFFFFFFFFFFFFFFLL
	# define kx_nf (0/0.0)
	# define kx_wf (1/0.0)
	# define kx_closesocket(x) close(x)
# endif 

// remove more clutter
# define kx_O printf
# define kx_R return
# define kx_Z static
# define kx_P(x,y) {if(x)kx_R(y);}
# define kx_U(x) kx_P(!(x),0)
# define kx_SW switch
# define kx_CS(n,x)	case n:x;break;
# define kx_CD default

# define kx_ZV kx_Z V
# define kx_ZK kx_Z K
# define kx_ZH kx_Z H
# define kx_ZI kx_Z I
# define kx_ZJ kx_Z J
# define kx_ZE kx_Z E
# define kx_ZF kx_Z F
# define kx_ZC kx_Z C
# define kx_ZS kx_Z S

# define kx_K1(f) K f(K x)
# define kx_K2(f) K f(K x,K y)
# define kx_TX(T,x) (*(T*)((G*)(x)+8))
# define kx_xr x->r
# define kx_xt x->t
# define kx_xu x->u
# define kx_xn x->n
# define kx_xx xK[0]
# define kx_xy xK[1]
# define kx_xg TX(G,x)
# define kx_xh TX(H,x)
# define kx_xi TX(I,x)
# define kx_xj TX(J,x)
# define kx_xe TX(E,x)
# define kx_xf TX(F,x)
# define kx_xs TX(S,x)
# define kx_xk TX(K,x)
# define kx_xG x->G0
# define kx_xH ((H*)kx_xG)
# define kx_xI ((I*)kx_xG)
# define kx_xJ ((J*)kx_xG)
# define kx_xE ((E*)kx_xG)
# define kx_xF ((F*)kx_xG)
# define kx_xS ((S*)kx_xG)
# define kx_xK ((K*)kx_xG)
# define kx_xC kx_xG
# define kx_xB ((G*)kx_xG)
}//kx
# endif


//# ifndef KX
//# define KX
//
//namespace kx {
//
//typedef const char* SS;
//typedef char*S,C;
//typedef unsigned char G;
//typedef short H;
//typedef int I;
//typedef long long J;
//typedef float E;
//typedef double F;
//typedef void V;
//
//typedef struct k0{
//			I r; // this counts the reference
//			H t  // t is the type of the K object. If t==-128 then this is an error.
//			 ,u;
//			union{
//					G g;
//					H h;
//					I i;
//					J j;
//					E e;
//					F f;
//					S s;
//					struct k0*k;
//					struct{I n;G G0[1];};
//			};
//		}*K;
//
////#include<string.h>
//// vector accessors, e.g. kF(x)[i] for float&datetime
//# define kx_kG(x)   ((x)->G0)
//# define kx_kC(x)   kx_kG(x)
//# define kx_kH(x)   ((H*)kx_kG(x))
//# define kx_kI(x)   ((I*)kx_kG(x))
//# define kx_kJ(x)   ((J*)kx_kG(x))
//# define kx_kE(x)   ((E*)kx_kG(x))
//# define kx_kF(x)   ((F*)kx_kG(x))
//# define kx_kS(x)   ((S*)kx_kG(x))
//# define kx_kK(x)   ((K*)kx_kG(x))
//
////      type bytes qtype    ctype  accessor
//# define kx_KB 1  // 1 boolean  char   kG
//# define kx_KG 4  // 1 byte     char   kG
//# define kx_KH 5  // 2 short    short  kH
//# define kx_KI 6  // 4 int      int    kI
//# define kx_KJ 7  // 8 long     int64  kJ
//# define kx_KE 8  // 4 real     float  kE
//# define kx_KF 9  // 8 float    double kF
//# define kx_KC 10 // 1 char     char   kC
//# define kx_KS 11 // * symbol   char*  kS
//# define kx_KP 12 // 8 timestampint64  kJ (nanoseconds from 2000.01.01)
//# define kx_KM 13 // 4 month    int    kI
//# define kx_KD 14 // 4 date     int    kI (days from 2000.01.01)
//# define kx_KZ 15 // 8 datetime double kF (days from 2000.01.01)
//# define kx_KN 16 // 8 timespan int64  kJ
//# define kx_KU 17 // 4 minute   int    kI
//# define kx_KV 18 // 4 second   int    kI
//# define kx_KT 19 // 4 time     int    kI (millisecond)
//
//// table,dict
//# define kx_XT 98 //   x->k is XD
//# define kx_XD 99 //   kK(x)[0] is keys. kK(x)[1] is values.
//
//# ifdef __cplusplus
//	extern"C"{
//# endif
//extern I khpun(const SS,I,const SS,I)
//		,khpu(const SS,I,const SS)
//		,khp(const SS,I)					// int c = khp("localhost", 1234); // Connect to a Kdb+ server on the localhost port 1234.
//		,ymd(I,I,I)						// Encode a year/month/day as an int
//		,dj(I);							// Create a Kdb+ date from an integer
//extern V r0(K)							// Decrement the object's reference count | r0(x) 
//		,sd0(I)							// Removes the callback on that socket. 
//		,m9()							// Note that k objects must be freed from the thread they are allocated within, and m9() should be called when the thread is about to complete, freeing up memory allocated for that thread's pool. 
//		,kclose(I);
//extern S sn(SS,I)						// S sn(string, n); 
//		,ss(SS);							// Intern a string | S ss(string); 
//
//extern K ktj(I,J)						// Create a timestamp	| K tj(I);
//		,ka(I)							// Create an atom		| K ka(I);
//		,kb(I)							// Create a boolean		| K kb(I); 
//		,kg(I)							// Create a byte		| K kg(I); 
//		,kh(I)							// Create a short		| K kh(I); 
//		,ki(I)							// Create an int		| K ki(I); 
//		,kj(J)							// Create a long		| K kj(J);		
//		,ke(F)							// Create a real		| K ke(F); 
//		,kf(F)							// Create a float		| K kf(F); 
//		,kc(I)							// Create a char		| K kc(I); 
//		,ks(SS)							// Create a symbol		| K ks(S); 
//		,kd(I)							// Create a date		| K kd(I); 
//		,kz(F)							// Create a datetime	| K kt(I); 
//		,kt(I)							// Create a time		| K kz(I); 
//		,sd1(I,K(*)(I))					// The void sd0(I); and K sd1(I, K(*)(I)); functions are for use with callbacks and are available only within kdb+ itself, i.e. used from a shared library loaded into kdb+. 
//		,dl(V*f,I)						// The dynamic link, K dl(V* f, I n), function takes a C function that would take n K objects as arguments and return a new K object and returns a q function
//		,ktn(I,I)						// Create a simple list | K ktn(type, length); 
//		,knk(I,...)						// Create a mixed list | K knk(n,x,y,z); 
//		,kp(SS)							// Create a string | K kp(string); 
//		,kpn(SS,I)						// Create an empty strong of length n | K kpn(string, n); 
//		,ja(K*,V*)						// Join an atom to a list | K ja(K*,V*); 
//		,js(K*,SS)						// Join a string to a list | K js(K*,S); 
//		,jk(K*,K)						// Join another K object to a list | K jk(K*,K); 
//		,k(I,const SS,...)				// k(-c,"a:2+2",(K)0); // Asynchronously set a to be 4 on the server. ; r = k(c,"b:til 100",(K)0); // Synchronously set b to be a list up to 100. 
//		,xT(K)							// Create a table from a dict | K xT(K); 
//		,xD(K,K)						// Create a dict | K xD(K,K); 
//		,ktd(K)							// Create a simple table from a keyed table | K ktd(K); 
//		,r1(K)							// Increment the object's reference count | r1(x)
//		,krr(SS)							// krr(S);
//		,orr(SS)
//		,dot(K,K)						// The K dot (K x, K y) function is the same as the q function .[x;y]. 
//		,b9(I,K)						// b9(preserveEnumerations,kObject);
//		,d9(K);							// will deserialize the byte stream in kObject returning a new kObject. 
//# ifdef __cplusplus
//}
//# endif
//
//// nulls(n?) and infinities(w?)
//# define kx_nh ((I)0xFFFF8000)
//# define kx_wh ((I)0x7FFF)
//# define kx_ni ((I)0x80000000)
//# define kx_wi ((I)0x7FFFFFFF)
//# ifdef WIN32
//	# define kx_nj ((J)0x8000000000000000)
//	# define kx_wj ((J)0x7FFFFFFFFFFFFFFF)
//	# define kx_nf (log(-1.0))
//	# define kx_wf (-log(0.0))
//	# define kx_isnan _isnan
//	# define kx_finite _finite
//	extern double log();
//# else 
//	# define kx_nj 0x8000000000000000LL
//	# define kx_wj 0x7FFFFFFFFFFFFFFFLL
//	# define kx_nf (0/0.0)
//	# define kx_wf (1/0.0)
//	# define kx_closesocket(x) close(x)
//# endif
//
//// remove more clutter
//# define kx_O printf
//# define kx_R return
//# define kx_Z static
//# define kx_P(x,y) {if(x)kx_R(y);}
//# define kx_U(x) kx_P(!(x),0)
//# define kx_SW switch
//# define kx_CS(n,x) case n:x;break;
//# define kx_CD default
//# define kx_DO(n,x) {I i=0,_i=(n);for(;i<_i;++i){x;}}
//
//# define kx_ZV kx_Z V
//# define kx_ZK kx_Z K
//# define kx_ZH kx_Z H
//# define kx_ZI kx_Z I
//# define kx_ZJ kx_Z J
//# define kx_ZE kx_Z E
//# define kx_ZF kx_Z F
//# define kx_ZC kx_Z C
//# define kx_ZS kx_Z S
//
//# define kx_K1(f) K f(K x)
//# define kx_K2(f) K f(K x,K y)
//# define kx_TX(T,x) (*(T*)((G*)(x)+8))
//# define kx_xr x->r
//# define kx_xt x->t
//# define kx_xu x->u
//# define kx_xn x->n
//# define kx_xx kx_xK[0]
//# define kx_xy kx_xK[1]
//# define kx_xg kx_TX(G,x)
//# define kx_xh kx_TX(H,x)
//# define kx_xi kx_TX(I,x)
//# define kx_xj kx_TX(J,x)
//# define kx_xe kx_TX(E,x)
//# define kx_xf kx_TX(F,x)
//# define kx_xs kx_TX(S,x)
//# define kx_xk kx_TX(K,x)
//# define kx_xG x->G0
//# define kx_xH ((H*)xG)
//# define kx_xI ((I*)xG)
//# define kx_xJ ((J*)xG)
//# define kx_xE ((E*)xG)
//# define kx_xF ((F*)xG)
//# define kx_xS ((S*)xG)
//# define kx_xK ((K*)xG)
//# define kx_xC kx_xG
//
//} // kx
//
//# endif
