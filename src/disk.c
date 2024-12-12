#include <stdio.h>
#include <sys/statvfs.h>

void get_disk()
{
	struct statvfs stat;

	if (statvfs("/", &stat) == 0)
	{
		long long total_size_bytes = stat.f_blocks * stat.f_bsize;
		double total_size_gb = (double)total_size_bytes / (1024 * 1024 * 1024);

		printf("disk: %.2f GB\n", total_size_gb);
	}
	else
	{
		perror("statvfs");
	}

	return;
}