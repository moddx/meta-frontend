//
// Created by Matthias Ervens on 29/11/18.
// Copyright (c) 2018 Matthias Ervens. All rights reserved.
//

#pragma once

#include "worker_adapter.h"

using namespace std;
using namespace META::Core;

namespace META { namespace Frontend {

class RemoteWorkerAdapter : WorkerAdapter {
public:
    RemoteWorkerAdapter(const ComputeUnit *computeUnit, string url, string apikey);
    future<vector<DataSet>> workOn(vector<DataSet> sets) override;
    vector<DataSet> workSeqOn(vector<DataSet> sets) override;

private:
    const string url;
    const string apikey;
};

}}

