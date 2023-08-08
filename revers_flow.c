#include "udf.h"
#include "sg.h"

DEFINE_PROFILE(reverse_profile,f_thread,i)
{
	real A[ND_ND];
	real u[ND_ND];
	real ds;
	real es[ND_ND];
	real A_by_es;
	real dr0[ND_ND];
	
	face_t face;
	int ID=7;
	Thread *t;
	cell_t c;
	
begin_f_loop(face, f_thread)
{
	BOUNDARY_FACE_GEOMETRY(face,f_thread,A,ds,es,A_by_es,dr0);
	ND_SET( u[0],u[1],u[2], F_U(face, f_thread), F_V(face, f_thread), F_W(face, f_thread));
	if( NV_DOT(u, es) <0.0 ) 
	{
		c=F_C0(face,f_thread);
		t=THREAD_T0(f_thread);
		
		F_PROFILE(face, f_thread,i)= C_T(c, t);
		
	}
		
end_f_loop(face, f_thread)
	
}

}