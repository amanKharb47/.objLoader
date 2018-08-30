#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LinkedList.h"
#include "Math.h"

void load(const char* fileName) {
	FILE *file = fopen(fileName, "r");
	char dataType[20];
	float *positionArray = NULL;
	float *textureArray = NULL;
	float *normalArray = NULL;

	if (file == NULL) {
		printf("Unable to open File");
		return;
	}

	pNode *headP = NULL;
	pNode *currentNodeP = NULL;
	pNode *tempP = NULL;

	tNode *headT = NULL;
	tNode *currentNodeT = NULL;
	tNode *tempT = NULL;

	nNode *headN = NULL;
	nNode *currentNodeN = NULL;
	nNode* tempN = NULL;

	while (1) {
		int result = fscanf(file, "%s", &dataType);
		if (result == EOF)
			break;

		if (strcmp(dataType, "v") == 0) {						//checking if the data is for vertexPosition
			float val1, val2, val3;
			fscanf(file, "%f %f %f", &val1, &val2, &val3);

			tempP = (pNode *)malloc(sizeof(pNode));		//creating new PositionNode and filling data
			tempP->pos.x = val1;
			tempP->pos.y = val2;
			tempP->pos.z = val3;

			if (headP != NULL) {									//adding Position Node to end of Linked List
				currentNodeP->nextNode = tempP;
				currentNodeP = tempP;
				currentNodeP->nextNode = NULL;
			}
			else {
				headP = currentNodeP = tempP;
			}
			++num_posNodes;
		}
		else if (strcmp(dataType, "vt") == 0) {
			float val1, val2;
			fscanf(file, "%f %f", &val1, &val2);

			tempT = (tNode *)malloc(sizeof(tNode));			//creating new TextureNode and filling data
			tempT->pos.x = val1;
			tempT->pos.y = val2;

			if (headT != NULL) {									//adding Texture Node to end of Linked List
				currentNodeT->nextNode = tempT;
				currentNodeT = tempT;
				currentNodeT->nextNode = NULL;
			}
			else {
				headT = currentNodeT = tempT;
			}
			++num_texNodes;
		}
		else if (strcmp(dataType, "vn") == 0) {
			float val1, val2, val3;
			fscanf(file, "%f %f %f", &val1, &val2, &val3);

			tempN = (nNode *)malloc(sizeof(nNode));			//creating new TextureNode and filling data
			tempN->pos.x = val1;
			tempN->pos.y = val2;
			tempN->pos.z = val3;

			if (headN != NULL) {									//adding Texture Node to end of Linked List
				currentNodeN->nextNode = tempN;
				currentNodeN = tempN;
				currentNodeN->nextNode = NULL;
			}
			else {
				headN = currentNodeN = tempN;
			}

			++num_norNodes;
		}
		else if (strcmp(dataType, "f") == 0) {
			printf("Positions: %d\nTextures: %d\nNormals: %d\n", num_posNodes, num_texNodes, num_norNodes);
			positionArray = (float *)malloc(sizeof(float) * 3 * num_posNodes);
			textureArray = (float *)malloc(sizeof(float) * 2 * num_texNodes);
			normalArray = (float *)malloc(sizeof(float) * 3 * num_norNodes);

			int i = 0;
			for (pNode *reader = headP; currentNodeP->nextNode != reader; reader = reader->nextNode) {
				positionArray[i] = reader->pos.x;
				positionArray[i + 1] = reader->pos.y;
				positionArray[i + 2] = reader->pos.z;
				printf("Vertex %d: %f %f %f\n", i/3, positionArray[i], positionArray[i + 1], positionArray[i + 2]);
				i += 3;
			}

			//we don't have textures for now
/*			i = 0;
			for (tNode *reader = headT; reader->nextNode != NULL; reader = reader->nextNode) {
				textureArray[i] = reader->pos.x;
				textureArray[i + 1] = reader->pos.y;
				printf("Texture %d: %f %f\n", i/2, textureArray[i], textureArray[i + 1], textureArray[i + 2]);
				i += 2;
			}
*/
			i = 0;
			for (nNode *reader = headN; reader->nextNode != NULL; reader = reader->nextNode) {
				normalArray[i] = reader->pos.x;
				normalArray[i + 1] = reader->pos.y;
				normalArray[i + 2] = reader->pos.z;
				printf("Normal %d: %f %f %f\n", i/3, normalArray[i], normalArray[i + 1], normalArray[i + 2]);
				i += 3;
			}
			break;
		}
	}
}

int main() {
	load("untitled.obj");
	getchar();
	return 0;
}