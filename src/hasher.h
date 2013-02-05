#ifndef FAST_CLUSTER_HASHER_H
#define FAST_CLUSTER_HASHER_H

#include <string>
#include <stdint.h>

namespace fast_cluster {

int64_t SimHash(const std::string &buf, int count = 10, int iters = 10);

}
#endif
