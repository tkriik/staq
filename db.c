#include <sys/mman.h>

#include <assert.h>
#include <stdint.h>
#include <stddef.h>

#include "db.h"

int
db_init_mem(struct db *db)
{
	uint8_t *buf;

	assert(db != NULL);

	buf = mmap(NULL, DB_INIT_SIZE, PROT_READ | PROT_WRITE,
	    MAP_ANONYMOUS | MAP_SHARED, -1, 0);
	if (buf == MAP_FAILED)
		return DB_MAP_FAILED;

	db->type = DB_TYPE_MEM;
	db->buf = buf;
	db->buf_len = 0;
	db->buf_max = DB_INIT_SIZE;

	return 0;
}

int
db_close(struct db *db)
{
	assert(db != NULL);

	switch (db->type) {
	case DB_TYPE_MEM:
		if (munmap(db->buf, db->buf_max) == -1)
			return DB_UNMAP_FAILED;
		return 0;
	default:
		return DB_BAD_TYPE;
	};
}

const char *
db_err_str(int err)
{
	switch (err) {
	case DB_MAP_FAILED:
		return "map failed";
	case DB_UNMAP_FAILED:
		return "unmap failed";
	case DB_BAD_TYPE:
		return "bad type";
	default:
		return "unknown error";
	};
}
