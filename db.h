#ifndef DB_H
#define DB_H

#define DB_INIT_SIZE 4096

enum db_type {
	DB_TYPE_MEM = 1
};

struct db {
	enum	 db_type type;
	uint8_t	*buf;
	size_t	 buf_len, buf_max;
	size_t	 msg_cnt;
};

enum db_err {
	DB_MAP_FAILED	= 1,
	DB_UNMAP_FAILED,
	DB_BAD_TYPE
};

int		 db_init_mem(struct db *);
int		 db_close(struct db *);
const char	*db_err_str(int);

#endif
