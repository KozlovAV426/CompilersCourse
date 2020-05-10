#pragma once

#include "ScopeLayer.h"

class ScopeLayerTree {
 public:
    explicit ScopeLayerTree(ScopeLayer* root);
    void Free(ScopeLayer* layer);
    ScopeLayer* root_;
};