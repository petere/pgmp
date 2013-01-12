MODULE_big = pgmp_plpython$(python_majorversion)
OBJS = pgmp_plpython.o

PG_CPPFLAGS = -I$(srcdir)/../src $(python_includespec)

EXTENSION = pgmp_plpythonu
DATA = pgmp_plpythonu--1.0.sql

REGRESS = pgmp_plpython

PG_CONFIG = pg_config
PGXS := $(shell $(PG_CONFIG) --pgxs)
include $(PGXS)
