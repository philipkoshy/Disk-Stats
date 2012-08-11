This program reads disk statistics from /proc/diskstats
For more information, see the kernel documentation here:
http://www.kernel.org/doc/Documentation/iostats.txt

To compile, just type:

make

You can run the tool continuously by using:

watch -n 1 ./disk_stats
