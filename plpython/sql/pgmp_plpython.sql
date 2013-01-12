CREATE EXTENSION plpythonu;
CREATE EXTENSION pgmp;
CREATE EXTENSION pgmp_plpythonu;


CREATE FUNCTION py_add(a mpz, b mpz) RETURNS mpz
LANGUAGE plpythonu
AS $$
return a + b
$$;

SELECT py_add('123'::mpz, '456'::mpz);