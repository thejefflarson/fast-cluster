#ifndef FAST_CLUSTER_HASHER_H
#define FAST_CLUSTER_HASHER_H

#include <string>
#include <stdint.h>

namespace fast_cluster {

int32_t SimHash(const std::string &buf, int count = 10);

}
#endif
