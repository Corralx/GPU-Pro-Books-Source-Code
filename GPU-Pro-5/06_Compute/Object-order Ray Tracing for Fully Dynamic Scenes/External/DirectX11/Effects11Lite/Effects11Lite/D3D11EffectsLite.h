//////////////////////////////////////////////////////////////////////////////
//
//  Copyright (C) Tobias Zirr.  All Rights Reserved.
//
//////////////////////////////////////////////////////////////////////////////

#pragma once

#include "D3DEffectsLiteCommon.h"
#include "D3D11.h"

/// @addtogroup D3DEffectsLite D3D Effects Lite
/// @{

/// Annotation info.
struct D3DEL_INT_ANNOTATION_INFO
{
	const char *Name;
	UINT ValueCount;
	D3DEFFECTSLITE_CONST_PTR_ACCESS(INT) Values;
};

/// Annotation info.
struct D3DEL_FLOAT_ANNOTATION_INFO
{
	const char *Name;
	UINT ValueCount;
	D3DEFFECTSLITE_CONST_PTR_ACCESS(FLOAT) Values;
};

/// Annotation info.
struct D3DEL_BOOL_ANNOTATION_INFO
{
	const char *Name;
	UINT ValueCount;
	D3DEFFECTSLITE_CONST_PTR_ACCESS(BOOL) Values;
};

/// Annotation info.
struct D3DEL_STRING_ANNOTATION_INFO
{
	const char *Name;
	UINT ValueCount;
	UINT ValueStride;
	D3DEFFECTSLITE_CONST_PTR_ACCESS(const char*) Values;
};

/// Annotation info.
struct D3DEL_ANNOTATION_BLOCK_INFO
{
	UINT FloatCount;
	UINT IntCount;
	UINT BoolCount;
	UINT StringCount;

	#define D3DEL_ANNOTATION_BLOCK_INFO_COUNT_BLOCK offsetof(D3DEL_ANNOTATION_BLOCK_INFO, Floats)

	D3DEFFECTSLITE_CONST_PTR_ACCESS(D3DEL_FLOAT_ANNOTATION_INFO) Floats;
	D3DEFFECTSLITE_CONST_PTR_ACCESS(D3DEL_INT_ANNOTATION_INFO) Ints;
	D3DEFFECTSLITE_CONST_PTR_ACCESS(D3DEL_BOOL_ANNOTATION_INFO) Bools;
	D3DEFFECTSLITE_CONST_PTR_ACCESS(D3DEL_STRING_ANNOTATION_INFO) Strings;
};

/// Struct type alias.
static const D3D_SHADER_VARIABLE_TYPE D3D_SVT_STRUCT = static_cast<D3D_SHADER_VARIABLE_TYPE>(D3D_SVT_VOID);

/// Variable info.
struct D3DEL_VARIABLE_INFO
{
	const char *Name;
	const char *Semantic;	///< Optional.
	D3DEFFECTSLITE_CONST_PTR_ACCESS(D3DEL_ANNOTATION_BLOCK_INFO) Annotations; ///< Optional.
	D3D_SHADER_VARIABLE_TYPE Type;
	D3DEFFECTSLITE_CONST_PTR_ACCESS(void) Info;
};

static const UINT D3DEL_BIND_POINT_AMBIGUOUS = UINT(-1);

/// Resource info.
struct D3DEL_RESOURCE_INFO
{
	D3DEFFECTSLITE_CONST_PTR_ACCESS(D3DEL_VARIABLE_INFO) Variable;
	UINT BindPoint;			///< Register if globally unambiguous, D3DEL_BIND_POINT_AMBIGUOUS otherwise.
	UINT SuccessorCount;	///< Number of additional resources in an array.
};

/// Constant info.
struct D3DEL_CONSTANT_INFO
{
	UINT Offset;
	UINT Stride;
	UINT Elements;
	USHORT Rows;
	USHORT Columns;
};

/// Variable info.
struct D3DEL_INT_VARIABLE_INFO
{
	D3DEFFECTSLITE_CONST_PTR_ACCESS(D3DEL_VARIABLE_INFO) Variable;
	D3DEL_CONSTANT_INFO Constant;
	UINT ValueCount;
	D3DEFFECTSLITE_CONST_PTR_ACCESS(INT) Values;
};

/// Variable info.
struct D3DEL_FLOAT_VARIABLE_INFO
{
	D3DEFFECTSLITE_CONST_PTR_ACCESS(D3DEL_VARIABLE_INFO) Variable;
	D3DEL_CONSTANT_INFO Constant;
	UINT ValueCount;
	D3DEFFECTSLITE_CONST_PTR_ACCESS(FLOAT) Values;
};

/// Variable info.
struct D3DEL_BOOL_VARIABLE_INFO
{
	D3DEFFECTSLITE_CONST_PTR_ACCESS(D3DEL_VARIABLE_INFO) Variable;
	D3DEL_CONSTANT_INFO Constant;
	UINT ValueCount;
	D3DEFFECTSLITE_CONST_PTR_ACCESS(BOOL) Values;
};

/// Variable info.
struct D3DEL_STRUCT_VARIABLE_INFO
{
	D3DEFFECTSLITE_CONST_PTR_ACCESS(D3DEL_VARIABLE_INFO) Variable;
	D3DEL_CONSTANT_INFO Constant;
	UINT ByteCount;
	D3DEFFECTSLITE_CONST_PTR_ACCESS(void) Bytes;
};

/// Variable info.
struct D3DEL_STRING_VARIABLE_INFO
{
	D3DEFFECTSLITE_CONST_PTR_ACCESS(D3DEL_VARIABLE_INFO) Variable;
	UINT ValueCount;
	D3DEFFECTSLITE_CONST_PTR_ACCESS(const char*) Values;
};

/// Constants info.
struct D3DEL_CONSTANT_BUFFER_INFO
{
	D3DEFFECTSLITE_CONST_PTR_ACCESS(D3DEL_VARIABLE_INFO) Variable;
	UINT BindPoint;		///< Register if globally unambiguous, D3DEL_BIND_POINT_AMBIGUOUS otherwise.
	UINT Size;

	UINT FloatCount;
	UINT IntCount;
	UINT BoolCount;
	UINT StructCount;

	D3DEFFECTSLITE_CONST_PTR_ACCESS(D3DEL_FLOAT_VARIABLE_INFO) Floats;
	D3DEFFECTSLITE_CONST_PTR_ACCESS(D3DEL_INT_VARIABLE_INFO) Ints;
	D3DEFFECTSLITE_CONST_PTR_ACCESS(D3DEL_BOOL_VARIABLE_INFO) Bools;
	D3DEFFECTSLITE_CONST_PTR_ACCESS(D3DEL_STRUCT_VARIABLE_INFO) Structs;
};

/// State info.
struct D3DEL11_RASTERIZER_STATE_INFO
{
	D3DEFFECTSLITE_CONST_PTR_ACCESS(D3DEL_VARIABLE_INFO) Variable;
	D3D11_RASTERIZER_DESC Desc;		// TODO: DX11.1?
	UINT SuccessorCount;			///< Number of additional state blocks in an array.
};
typedef D3DEL11_RASTERIZER_STATE_INFO D3DEL_RASTERIZER_STATE_INFO;

/// State info.
struct D3DEL11_DEPTH_STENCIL_STATE_INFO
{
	D3DEFFECTSLITE_CONST_PTR_ACCESS(D3DEL_VARIABLE_INFO) Variable;
	D3D11_DEPTH_STENCIL_DESC Desc;	// TODO: DX11.1?
	UINT SuccessorCount;			///< Number of additional state blocks in an array.
};
typedef D3DEL11_DEPTH_STENCIL_STATE_INFO D3DEL_DEPTH_STENCIL_STATE_INFO;

/// State info.
struct D3DEL11_BLEND_STATE_INFO
{
	D3DEFFECTSLITE_CONST_PTR_ACCESS(D3DEL_VARIABLE_INFO) Variable;
	D3D11_BLEND_DESC Desc;	// TODO: DX11.1?
	UINT SuccessorCount;	///< Number of additional state blocks in an array.
};
typedef D3DEL11_BLEND_STATE_INFO D3DEL_BLEND_STATE_INFO;

/// State info.
struct D3DEL11_SAMPLER_STATE_INFO
{
	D3DEFFECTSLITE_CONST_PTR_ACCESS(D3DEL_VARIABLE_INFO) Variable;
	D3D11_SAMPLER_DESC Desc;		// DX11.1?
	UINT BindPoint;					///< Register if globally unambiguous, D3DEL_BIND_POINT_AMBIGUOUS otherwise.
	UINT SuccessorCount;			///< Number of additional state blocks in an array.
};
typedef D3DEL11_SAMPLER_STATE_INFO D3DEL_SAMPLER_STATE_INFO;

/// State info.
struct D3DEL_CONSTANT_BUFFER_BIND_INFO
{
	D3DEFFECTSLITE_CONST_PTR_ACCESS(D3DEL_CONSTANT_BUFFER_INFO) Resource;
	UINT Register;
};

/// State info.
struct D3DEL_RESOURCE_BIND_INFO
{
	D3DEFFECTSLITE_CONST_PTR_ACCESS(D3DEL_RESOURCE_INFO) Resource;
	UINT Register;
};

/// State info.
struct D3DEL_SAMPLER_STATE_BIND_INFO
{
	D3DEFFECTSLITE_CONST_PTR_ACCESS(D3DEL_SAMPLER_STATE_INFO) Sampler;
	UINT Register;
};

/// State info.
struct D3DEL_SHADER_BINDING_INFO
{
	UINT SamplerCount;

	UINT ConstantBufferCount;
	UINT TextureBufferCount;
	UINT ResourceCount;
	UINT UAVCount;

	#define D3DEL_SHADER_BINDING_INFO_COUNT_BLOCK offsetof(D3DEL_SHADER_BINDING_INFO, Samplers)

	D3DEFFECTSLITE_CONST_PTR_ACCESS(D3DEL_SAMPLER_STATE_BIND_INFO) Samplers;

	D3DEFFECTSLITE_CONST_PTR_ACCESS(D3DEL_CONSTANT_BUFFER_BIND_INFO) ConstantBuffers;
	D3DEFFECTSLITE_CONST_PTR_ACCESS(D3DEL_CONSTANT_BUFFER_BIND_INFO) TextureBuffers;
	D3DEFFECTSLITE_CONST_PTR_ACCESS(D3DEL_RESOURCE_BIND_INFO) Resources;
	D3DEFFECTSLITE_CONST_PTR_ACCESS(D3DEL_RESOURCE_BIND_INFO) UAVs;
};

struct D3DEL_SHADER_INFO;

/// Shader info.
struct D3DEL11_STREAM_OUT_INFO
{
	D3DEFFECTSLITE_CONST_PTR_ACCESS(D3DEL_SHADER_INFO) Shader;
	UINT ElementCount;
	D3DEFFECTSLITE_CONST_PTR_ACCESS(D3D11_SO_DECLARATION_ENTRY) Elements;
	UINT BufferCount;
	D3DEFFECTSLITE_CONST_PTR_ACCESS(UINT) BufferStrides;
	UINT RasterizedStream;
};
typedef D3DEL11_STREAM_OUT_INFO D3DEL_STREAM_OUT_INFO;

/// Shader info.
struct D3DEL_SHADER_INFO
{
	D3DEFFECTSLITE_CONST_PTR_ACCESS(D3DEL_VARIABLE_INFO) Variable;			///< Optional, i.e. if not inline.
	UINT ByteCount;
	const void *ByteCode;
	D3DEFFECTSLITE_CONST_PTR_ACCESS(D3DEL_SHADER_BINDING_INFO) Bindings;
	D3DEFFECTSLITE_CONST_PTR_ACCESS(D3DEL_STREAM_OUT_INFO) StreamOut;		///< Optional.
	UINT SuccessorCount;													///< Number of additional shaders in an array.
};

/// State info.
struct D3DEL_PASS_SHADER_BINDING_INFO
{
	D3DEFFECTSLITE_CONST_PTR_ACCESS(D3DEL_SHADER_INFO) VertexShader;	///< Optional.
	D3DEFFECTSLITE_CONST_PTR_ACCESS(D3DEL_SHADER_INFO) PixelShader;		///< Optional.
	D3DEFFECTSLITE_CONST_PTR_ACCESS(D3DEL_SHADER_INFO) ComputeShader;	///< Optional.
	D3DEFFECTSLITE_CONST_PTR_ACCESS(D3DEL_SHADER_INFO) GeometryShader;	///< Optional.
	D3DEFFECTSLITE_CONST_PTR_ACCESS(D3DEL_SHADER_INFO) HullShader;		///< Optional.
	D3DEFFECTSLITE_CONST_PTR_ACCESS(D3DEL_SHADER_INFO) DomainShader;	///< Optional.
};

/// State info.
struct D3DEL_RASTERIZER_STATE_BIND_INFO
{
	D3DEFFECTSLITE_CONST_PTR_ACCESS(D3DEL_RASTERIZER_STATE_INFO) Block;		///< Optional.
};

/// State info.
struct D3DEL_DEPTH_STENCIL_STATE_BIND_INFO
{
	D3DEFFECTSLITE_CONST_PTR_ACCESS(D3DEL_DEPTH_STENCIL_STATE_INFO) Block;	///< Optional.
	UINT StencilRef;
};

/// State info.
struct D3DEL_BLEND_STATE_BIND_INFO
{
	D3DEFFECTSLITE_CONST_PTR_ACCESS(D3DEL_BLEND_STATE_INFO) Block;	///< Optional.
	FLOAT BlendFactor[4];
	UINT SampleMask;
};

/// State info.
struct D3DEL_RENDER_TARGET_BIND_INFO
{
	D3DEFFECTSLITE_CONST_PTR_ACCESS(D3DEL_RESOURCE_INFO) RenderTargets[D3D11_SIMULTANEOUS_RENDER_TARGET_COUNT];	///< Optional.
	D3DEFFECTSLITE_CONST_PTR_ACCESS(D3DEL_RESOURCE_INFO) DepthStencilTarget;									///< Optional.
};

/// State info.
struct D3DEL_PASS_STATE_BINDING_INFO
{
	D3DEFFECTSLITE_CONST_PTR_ACCESS(D3DEL_RASTERIZER_STATE_BIND_INFO) RasterizerState;		///< Optional.
	D3DEFFECTSLITE_CONST_PTR_ACCESS(D3DEL_DEPTH_STENCIL_STATE_BIND_INFO) DepthStencilState;	///< Optional.
	D3DEFFECTSLITE_CONST_PTR_ACCESS(D3DEL_BLEND_STATE_BIND_INFO) BlendState;				///< Optional.
	
	D3DEFFECTSLITE_CONST_PTR_ACCESS(D3DEL_RENDER_TARGET_BIND_INFO) Targets;					///< Optional.
};

/// Group info.
struct D3DEL_PASS_INFO
{
	const char *Name;
	D3DEFFECTSLITE_CONST_PTR_ACCESS(D3DEL_ANNOTATION_BLOCK_INFO) Annotations;	///< Optional.

	D3DEL_PASS_STATE_BINDING_INFO State;
	D3DEL_PASS_SHADER_BINDING_INFO Shaders;
};

/// Group info.
struct D3DEL_TECHNIQUE_INFO
{
	const char *Name;
	D3DEFFECTSLITE_CONST_PTR_ACCESS(D3DEL_ANNOTATION_BLOCK_INFO) Annotations;	///< Optional.

	UINT PassCount;
	D3DEFFECTSLITE_CONST_PTR_ACCESS(D3DEL_PASS_INFO) Passes;
};

/// Group info.
struct D3DEL_GROUP_INFO
{
	const char *Name;
	D3DEFFECTSLITE_CONST_PTR_ACCESS(D3DEL_ANNOTATION_BLOCK_INFO) Annotations;	///< Optional.

	UINT TechniqueCount;
	D3DEFFECTSLITE_CONST_PTR_ACCESS(D3DEL_TECHNIQUE_INFO) Techniques;
};

// TODO: State Masks?

/// Variable info.
struct D3DEL_EFFECT_CONSTANT_INFO
{
	UINT BoolCount;
	UINT IntCount;
	UINT FloatCount;
	UINT StructCount;
	UINT StringCount;

	#define D3DEL_EFFECT_CONSTANT_INFO_COUNT_BLOCK offsetof(D3DEL_EFFECT_CONSTANT_INFO, Bools)
	
	D3DEFFECTSLITE_CONST_PTR_ACCESS(D3DEL_BOOL_VARIABLE_INFO) Bools;
	D3DEFFECTSLITE_CONST_PTR_ACCESS(D3DEL_INT_VARIABLE_INFO) Ints;
	D3DEFFECTSLITE_CONST_PTR_ACCESS(D3DEL_FLOAT_VARIABLE_INFO) Floats;
	D3DEFFECTSLITE_CONST_PTR_ACCESS(D3DEL_STRUCT_VARIABLE_INFO) Structs;
	D3DEFFECTSLITE_CONST_PTR_ACCESS(D3DEL_STRING_VARIABLE_INFO) Strings;
};

/// Variable info.
struct D3DEL_EFFECT_RESOURCE_INFO
{
	UINT ConstantBufferCount;
	UINT TextureBufferCount;
	UINT ResourceCount;
	UINT UAVCount;
	UINT RenderTargetCount;
	UINT DepthStencilTargetCount;

	#define D3DEL_EFFECT_RESOURCE_INFO_COUNT_BLOCK offsetof(D3DEL_EFFECT_RESOURCE_INFO, ConstantBuffers)

	D3DEFFECTSLITE_CONST_PTR_ACCESS(D3DEL_CONSTANT_BUFFER_INFO) ConstantBuffers;
	D3DEFFECTSLITE_CONST_PTR_ACCESS(D3DEL_CONSTANT_BUFFER_INFO) TextureBuffers;
	D3DEFFECTSLITE_CONST_PTR_ACCESS(D3DEL_RESOURCE_INFO) Resources;
	D3DEFFECTSLITE_CONST_PTR_ACCESS(D3DEL_RESOURCE_INFO) UAVs;
	D3DEFFECTSLITE_CONST_PTR_ACCESS(D3DEL_RESOURCE_INFO) RenderTargets;
	D3DEFFECTSLITE_CONST_PTR_ACCESS(D3DEL_RESOURCE_INFO) DepthStencilTargets;
};

/// Variable info.
struct D3DEL_EFFECT_STATE_INFO
{
	UINT RasterizerStateCount;
	UINT DepthStencilStateCount;
	UINT BlendStateCount;
	UINT SamplerStateCount;

	#define D3DEL_EFFECT_STATE_INFO_COUNT_BLOCK offsetof(D3DEL_EFFECT_STATE_INFO, RasterizerState)

	D3DEFFECTSLITE_CONST_PTR_ACCESS(D3DEL_RASTERIZER_STATE_INFO) RasterizerState;
	D3DEFFECTSLITE_CONST_PTR_ACCESS(D3DEL_DEPTH_STENCIL_STATE_INFO) DepthStencilState;
	D3DEFFECTSLITE_CONST_PTR_ACCESS(D3DEL_BLEND_STATE_INFO) BlendState;
	D3DEFFECTSLITE_CONST_PTR_ACCESS(D3DEL_SAMPLER_STATE_INFO) SamplerState;
};

/// Shader info.
struct D3DEL_EFFECT_SHADER_INFO
{
	UINT VertexShaderCount;
	UINT PixelShaderCount;
	UINT ComputeShaderCount;
	UINT GeometryShaderCount;
	UINT HullShaderCount;
	UINT DomainShaderCount;
	UINT StreamOutCount;

	#define D3DEL_EFFECT_SHADER_INFO_COUNT_BLOCK offsetof(D3DEL_EFFECT_SHADER_INFO, VertexShaders)

	D3DEFFECTSLITE_CONST_PTR_ACCESS(D3DEL_SHADER_INFO) VertexShaders;
	D3DEFFECTSLITE_CONST_PTR_ACCESS(D3DEL_SHADER_INFO) PixelShaders;
	D3DEFFECTSLITE_CONST_PTR_ACCESS(D3DEL_SHADER_INFO) ComputeShaders;
	D3DEFFECTSLITE_CONST_PTR_ACCESS(D3DEL_SHADER_INFO) GeometryShaders;
	D3DEFFECTSLITE_CONST_PTR_ACCESS(D3DEL_SHADER_INFO) HullShaders;
	D3DEFFECTSLITE_CONST_PTR_ACCESS(D3DEL_SHADER_INFO) DomainShaders;
	D3DEFFECTSLITE_CONST_PTR_ACCESS(D3DEL_STREAM_OUT_INFO) StreamOut;
};

/// Effect info.
struct D3DEL_EFFECT_INFO
{
	UINT VariableCount;
	
	UINT GroupCount;
	UINT TechniqueCount;
	UINT PassCount;
	
	#define D3DEL_EFFECT_INFO_COUNT_BLOCK offsetof(D3DEL_EFFECT_INFO, Variables)

	D3DEFFECTSLITE_CONST_PTR_ACCESS(D3DEL_VARIABLE_INFO) Variables;

	D3DEFFECTSLITE_CONST_PTR_ACCESS(D3DEL_GROUP_INFO) Groups;
	D3DEFFECTSLITE_CONST_PTR_ACCESS(D3DEL_TECHNIQUE_INFO) Techniques;
	D3DEFFECTSLITE_CONST_PTR_ACCESS(D3DEL_PASS_INFO) Passes;

	D3DEL_EFFECT_CONSTANT_INFO Constants;
	D3DEL_EFFECT_RESOURCE_INFO Resources;
	D3DEL_EFFECT_STATE_INFO State;
	D3DEL_EFFECT_SHADER_INFO Shaders;
};

/// Reflects a D3D11 effect.
class D3DEFFECTSLITE_INTERFACE D3DEffectsLiteReflection : public IUnknown
{
	D3DEFFECTSLITE_INTERFACE_BEHAVIOR(D3DEffectsLiteReflection)

public:
	/// Gets the effect info.
	virtual const D3DEL_EFFECT_INFO* D3DEFFECTSLITE_STDCALL GetInfo() const = 0;

	/// Gets a variable.
	virtual const D3DEL_VARIABLE_INFO* D3DEFFECTSLITE_STDCALL GetVariableByName(const char *name) const = 0;
	/// Gets a variable.
	virtual const D3DEL_VARIABLE_INFO* D3DEFFECTSLITE_STDCALL GetVariableBySemantic(const char *semantic) const = 0;

	/// Gets a group.
	virtual const D3DEL_GROUP_INFO* D3DEFFECTSLITE_STDCALL GetGroup(const char *name) const = 0;
	/// Gets a technique.
	virtual const D3DEL_TECHNIQUE_INFO* D3DEFFECTSLITE_STDCALL GetTechnique(const char *name) const = 0;
	/// Gets a technique.
	virtual const D3DEL_TECHNIQUE_INFO* D3DEFFECTSLITE_STDCALL GetTechnique(const char *name, const D3DEL_GROUP_INFO *group) const = 0;
	/// Gets a pass.
	virtual const D3DEL_PASS_INFO* D3DEFFECTSLITE_STDCALL GetPass(const char *name, const D3DEL_TECHNIQUE_INFO *technique) const = 0;
};

/// Creates an effect reflection interface.
D3DEFFECTSLITE_API D3DEffectsLiteReflection* D3DEFFECTSLITE_STDCALL D3DELReflectEffect(const void *bytes, UINT byteCount, D3DEffectsLiteAllocator *pScratchAllocator);

#ifndef D3DEFFECTSLITE_NO_CPP

namespace D3DEffectsLite
{
	typedef D3DEL_EFFECT_CONSTANT_INFO EffectConstantInfo;
	typedef D3DEL_EFFECT_RESOURCE_INFO EffectResourceInfo;
	typedef D3DEL_EFFECT_STATE_INFO EffectStateInfo;
	typedef D3DEL_EFFECT_SHADER_INFO EffectShaderInfo;
	typedef D3DEL_EFFECT_INFO EffectInfo;

	typedef D3DEL_RASTERIZER_STATE_BIND_INFO RasterizerStateBindInfo;
	typedef D3DEL_DEPTH_STENCIL_STATE_BIND_INFO DepthStencilStateBindInfo;
	typedef D3DEL_BLEND_STATE_BIND_INFO BlendStateBindInfo;
	typedef D3DEL_RENDER_TARGET_BIND_INFO RenderTargetBindInfo;
	typedef D3DEL_PASS_STATE_BINDING_INFO PassStateBindingInfo;

	typedef D3DEL_SAMPLER_STATE_BIND_INFO SamplerStateBindInfo;
	typedef D3DEL_CONSTANT_BUFFER_BIND_INFO ConstantBufferBindInfo;
	typedef D3DEL_RESOURCE_BIND_INFO ResourceBindInfo;
	typedef D3DEL_PASS_SHADER_BINDING_INFO PassShaderBindingInfo;

	typedef D3DEL_GROUP_INFO GroupInfo;
	typedef D3DEL_TECHNIQUE_INFO TechniqueInfo;
	typedef D3DEL_PASS_INFO PassInfo;

	typedef D3DEL_INT_ANNOTATION_INFO IntAnnotationInfo;
	typedef D3DEL_FLOAT_ANNOTATION_INFO FloatAnnotationInfo;
	typedef D3DEL_BOOL_ANNOTATION_INFO BoolAnnotationInfo;
	typedef D3DEL_STRING_ANNOTATION_INFO StringAnnotationInfo;

	typedef D3DEL_ANNOTATION_BLOCK_INFO AnnotationBlockInfo;
	typedef D3DEL_VARIABLE_INFO VariableInfo;

	static const UINT BindPointAmbiguous = D3DEL_BIND_POINT_AMBIGUOUS;

	typedef D3DEL_RESOURCE_INFO ResourceInfo;
	
	typedef D3DEL_CONSTANT_INFO ConstantInfo;
	typedef D3DEL_INT_VARIABLE_INFO IntVariableInfo;
	typedef D3DEL_FLOAT_VARIABLE_INFO FloatVariableInfo;
	typedef D3DEL_BOOL_VARIABLE_INFO BoolVariableInfo;
	typedef D3DEL_STRUCT_VARIABLE_INFO StructVariableInfo;
	typedef D3DEL_STRING_VARIABLE_INFO StringVariableInfo;
	typedef D3DEL_CONSTANT_BUFFER_INFO ConstantBufferInfo;

	typedef D3DEL_RASTERIZER_STATE_INFO RasterizerStateInfo;
	typedef D3DEL_DEPTH_STENCIL_STATE_INFO DepthStencilStateInfo;
	typedef D3DEL_BLEND_STATE_INFO BlendStateInfo;
	typedef D3DEL_SAMPLER_STATE_INFO SamplerStateInfo;
	
	typedef D3DEL_SHADER_BINDING_INFO ShaderBindingInfo;
	typedef D3DEL_SHADER_INFO ShaderInfo;
	typedef D3DEL_STREAM_OUT_INFO StreamOutInfo;

	typedef D3DEffectsLiteReflection Reflection;

	D3DEFFECTSLITE_API Reflection* D3DEFFECTSLITE_STDCALL ReflectEffect(const void *bytes, UINT byteCount, Allocator *pScratchAllocator = nullptr);

} // namespace

#endif

/// @}