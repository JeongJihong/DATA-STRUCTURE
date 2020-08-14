#include "MyContact.h"

int main(void)
{
	MyHash c;

	if (!c.hash_init(10))
		return 1;

	c.hash_dataload();
	c.hash_display();

	c.hash_add("JeongJihong", "010-9177-8547","","052-258-8547", "jjh1731@pnu.ac.kr", "201624580");
	c.hash_display();

	c.hash_delete("Honggildong");
	c.hash_display();

	c.hash_modify("JeongJihong", "010-1234-5678", "010-1111-2222", "052-123-4567", "kk@pnu.ac.kr", "20000102");
	c.hash_display();

	c.hash_check("JeongJihong");
	return 1;
}