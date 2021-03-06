#include "Math.h"
#include <stdlib.h>

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

static int num_posNodes = 0;
static int num_texNodes = 0;
static int num_norNodes = 0;
static int num_indexNodes = 0;

typedef struct PositionNode {
	vec3 pos;
	struct PositionNode *nextNode;
} pNode;

typedef struct {
	vec2 pos;
	struct TextureNode *nextNode;
} tNode;

typedef struct NormalNode {
	vec3 pos;
	struct NormalNode *nextNode;
} nNode;

typedef struct IndexNode {
	int p1, p2, p3;
	struct IndexNode *nextNode;
} iNode;

#endif