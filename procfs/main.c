#include <linux/module.h>
#include <linux/init.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>

MODULE_LICENSE("Dual BSD/GPL");

#define PROCNAME "driver/sample"
/*
#define DUMMY_BUFSIZ 4096
static char dummy[DUMMY_BUFSIZ];


static int sample_read_proc(char *page, char **start, off_t off, 
		int count, int *eof, void *data)
{
	int len;

	printk("page=%p *start=%p off=%d count=%d *eof=%d data=%p\n",
			page, *start, (int)off, count, *eof, data);

	len = DUMMY_BUFSIZ;
	if (len > PAGE_SIZE)
		return -ENOBUFS;

	memcpy(page, dummy, len);
	*eof = 1;

	printk("len=%d (%s)\n", len, __func__);
	return (len);
}
*/

static int sample_proc_open(struct inode *inode, struct file *filp)
{
	seq_printf("%s called\n", __func__);
	return 0;
}

ssize_t sample_proc_read(struct file *filp, char __user *buf, size_t count, loff_t *f_pos)
{
	seq_printf("%s called\n", __func__);
        int retval;
	retval = 9453;
        return retval;
}

static const struct file_operations sameple_proc_fops = {
  .owner = THIS_MODULE,
  .open = sample_proc_open,
  .read = sample_proc_read,
};

static int sample_init(void)
{
	struct proc_dir_entry *entry;
	//int i;

	/* add /proc */
	//entry = create_proc_read_entry(PROCNAME, S_IRUGO | S_IWUGO, NULL, sample_read_proc, NULL);
	entry = proc_create(PROCNAME, 0, NULL, &sameple_proc_fops);
	if (entry == NULL) {
		printk(KERN_WARNING "sample: unable to create /proc entry\n");
	}
	/*
	for (i = 0 ; i < DUMMY_BUFSIZ ; i++) {
		dummy[i] = 'A' + (i % 26);
	}
	*/
	printk("driver loaded\n");
		
	return 0;
}

static void sample_exit(void)
{
	remove_proc_entry(PROCNAME, NULL);

	printk(KERN_ALERT "driver unloaded\n");
}

module_init(sample_init);
module_exit(sample_exit);

