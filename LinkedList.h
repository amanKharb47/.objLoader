#include "Math.h"
#include <stdlib.h>

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

static unsigned int num_posNodes = 0;
static unsigned int num_texNodes = 0;
static unsigned int num_norNodes = 0;

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

#endif