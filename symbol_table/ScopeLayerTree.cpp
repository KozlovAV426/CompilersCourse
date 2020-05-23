#include "ScopeLayerTree.h"

ScopeLayerTree::ScopeLayerTree(ScopeLayer* root) : root_(root) {}

void ScopeLayerTree::Free(ScopeLayer* layer) {
  for (size_t i = 0; i < layer->children_.size(); ++i) {
    Free(layer->children_[i]);
  }
  if (layer->children_.empty())
    return;
  for (size_t i = 0; i < layer->children_.size(); ++i) {
    delete layer->children_[i];
  }
}