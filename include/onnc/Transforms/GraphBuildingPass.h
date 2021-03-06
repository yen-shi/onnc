//===- GraphBuildingPass.h ------------------------------------------------===//
//
//                             The ONNC Project
//
// See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
#ifndef ONNC_TRANSFORM_GRAPH_BUILDING_H
#define ONNC_TRANSFORM_GRAPH_BUILDING_H
#include <onnc/Core/ModulePass.h>
#include <onnc/IR/ComputeGraph.h>
#include <onnc/Config/ONNX.h>

namespace onnc {

/** \class GraphBuildingPass
 *  \brief GraphBuildingPass converts ONNX node to ComputeOperator and creates
 *  ComputeGraph objects for subgraph in ONNX.
 */
class GraphBuildingPass : public ModulePass
{
public:
  GraphBuildingPass() = default;

  virtual ~GraphBuildingPass() { }

  StringRef getPassName() const override { return "GraphBuilding"; }

  Pass::ReturnType runOnModule(::onnc::Module &pModule) override;

  virtual Pass::ReturnType runOnGraphs(xGraph& pTG, ComputeGraph& pCG) = 0;
};

} // namespace of onnc

#endif
