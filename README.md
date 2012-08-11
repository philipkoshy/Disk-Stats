Disk-Stats
==========

This program reads disk statistics from

	/proc/diskstats

For more information, see the kernel documentation here:

http://www.kernel.org/doc/Documentation/iostats.txt

Dependencies
============

This code was tested using Ubuntu 12.04 64-bit Desktop Edition

	sudo apt-get install g++ libboost-all-dev

Compilation
===========

To compile, just type:

	make


Running the tool
================

You can run the tool continuously by using:

	watch -n 1 ./disk_stats
