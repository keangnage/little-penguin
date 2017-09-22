#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/miscdevice.h>
#include <linux/init.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Knage");
MODULE_DESCRIPTION("Fortytwo misc device driver.");

static int misc_open(struct inode *inode, struct file *file) {
  printk(KERN_NOTICE "open!!\n");
  return 0;
}

static int misc_close(struct inode *inodep, struct file *filp) {
  return 0;
}

static ssize_t misc_write(struct file *file, const char __user *buf,
  size_t len, loff_t *pppos)
{
  return 0;
}

static ssize_t misc_read(struct file *file, const char __user *buf,
  size_t len, loff_t *pppos)
{
  printk(KERN_NOTICE "knage\n");
  return 0;
}

static const struct file_operations misc_fops = {
  .owner		=  THIS_MODULE,
  .open     =  misc_open,
  .write    =  misc_write,
  .read     =  misc_read,
  .release  =  misc_close,
  .llseek   =  no_llseek,
};

struct miscdevice misc_device = {
  .minor = MISC_DYNAMIC_MINOR,
  .name  = "fortytwo",
  .fops  = &misc_fops
};

static int __init misc_init(void)
{
	if (misc_register(&misc_device))
		printk(KERN_ERR "Unable register misc device");
  return 0;
}
module_init(misc_init);

static void __exit misc_exit(void)
{
      misc_deregister(&misc_device);
}
module_exit(misc_exit);