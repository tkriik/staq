#include <stdint.h>
#include <stdio.h>

#include "db.h"

int
main(void)
{
	int rc;
	struct db db;

	rc = db_init_mem(&db);
	if (rc != 0)
		printf("failed to initialize database: %s\n", db_err_str(rc));

	rc = db_close(&db);
	if (rc != 0)
		printf("failed to close database: %s\n", db_err_str(rc));

	return 0;
}
