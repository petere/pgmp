#include "postgres.h"
#include "fmgr.h"
#include "plpython.h"
#include "pmpz.h"

PG_MODULE_MAGIC;

PG_FUNCTION_INFO_V1(mpz_to_plpython);
Datum mpz_to_plpython(PG_FUNCTION_ARGS);

Datum
mpz_to_plpython(PG_FUNCTION_ARGS)
{
	const mpz_t z;
    char	   *buf;
	PyObject   *po;

	/* see pmpz_out() */
	PGMP_GETARG_MPZ(z, 0);
	buf = palloc(mpz_sizeinbase(z, 10) + 2);
	po = PyInt_FromString(mpz_get_str(buf, 10, z), NULL, 10);

	return PointerGetDatum(po);
}
