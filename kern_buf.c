#include <linux/linkage.h>
#include <linux/kernel.h>
#include <linux/slab.h>
#include <linux/uaccess.h>

asmlinkage long sys_kern_buf(int mode, void *p, int *b, size_t t)
{
	int *j, *i, *k;

	if (mode == 1) {
		i = kmalloc(t, GFP_KERNEL);
		copy_from_user(i, p, t);
		copy_to_user(b, &i, sizeof(int));
	}

	else if (mode == 2) {
		k = (void *) *b;
		copy_to_user(p, k, t);
	}

	else if (mode == 0) {
		k = (void *) *b;
		kfree(k);
	}

	return *b;
}
