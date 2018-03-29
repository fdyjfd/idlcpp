#import "Reference.i"
#import "ClassType.i"

#{
#include "Utility.h"
#}

namespace pafcore
{

#{
	class Reference;
	class InstanceMethod;
	class StaticMethod;
	class Variant;
#}

	class #PAFCORE_EXPORT CallBack : Reference
	{
#{
		friend struct Delegate;
	public:
		PAF_DECL_REFCOUNT_INTERFACE_DUMMY_IMPL;
		virtual void invoke(Variant* result, Variant** args, int_t numArgs) = 0;
		virtual bool equal(CallBack* arg) = 0;
		CallBack* getNext()
		{
			return m_next;
		}
	protected:
		CallBack* m_next;
#}
	};

	class #PAFCORE_EXPORT FunctionCallBack : CallBack
	{
#{
		friend struct Delegate;
	public:
		static FunctionCallBack* New(void* function, void* userData);
	public:
		virtual void invoke(Variant* result, Variant** args, int_t numArgs);
		virtual bool equal(CallBack* arg);
	public:
		void* m_function;
		void* m_userData;
#}
	};

	class #PAFCORE_EXPORT InstanceMethodCallBack : CallBack
	{
#{
		friend struct Delegate;
	public:
		static InstanceMethodCallBack* New(InstanceMethod* instanceMethod, Reference* object);
	public:
		virtual void invoke(Variant* result, Variant** args, int_t numArgs);
		virtual bool equal(CallBack* arg);
	protected:
		InstanceMethod* m_instanceMethod;
		Reference* m_object;
#}
	};

	class #PAFCORE_EXPORT StaticMethodCallBack : CallBack
	{
#{
		friend struct Delegate;
	public:
		static StaticMethodCallBack* New(StaticMethod* staticMethod);
	public:
		virtual void invoke(Variant* result, Variant** args, int_t numArgs);
		virtual bool equal(CallBack* arg);
	protected:
		StaticMethod* m_staticMethod;
#}
	};

	struct #PAFCORE_EXPORT Delegate
	{
		InstanceMethodCallBack* addInstanceMethod(Reference* object, const char* instanceMethodName);
		void removeInstanceMethod(Reference* object, const char* instanceMethodName);
		StaticMethodCallBack* addStaticMethod(ClassType* classType, const char* staticMethodName);
		void removeStaticMethod(ClassType* classType, const char* staticMethodName);
		void addCallBack(CallBack* callBack);
		void removeCallBack(CallBack* callBack);
#{
	public:
		Delegate();
		~Delegate();
	public:
		FunctionCallBack* addFunction(void* function, void* userData);
		void removeFunction(void* function, void* userData);
		CallBack* getCallBack()
		{
			return m_callBackList;
		}
	protected:
		CallBack* m_callBackList;
#} 
	};


	delegate #PAFCORE_EXPORT void EventHandler(Reference* sender);
}
