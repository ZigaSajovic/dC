#include "tau.h"
#include <util.h>

namespace dCpp{
    tau::tau(mapping func, dTau primitive)
    {
        this->primitive=primitive;
        this->func=func;
    }

    tau::~tau(){}

    var tau::operator()(const var& v){
        var out;
        out.id=this->func(v.id);
        out.order=v.order;
        if(v.order>0){
            for_each_copy(v.dTau.get()->begin(),v.dTau.get()->end(),inserter(*(out.dTau.get()),out.dTau.get()->begin()),
                mul_make_pair<std::pair<var*,var> , std::map<var*,var>::iterator, var >, this->primitive(v.reduce()));
        }
        return out;
    }
}


