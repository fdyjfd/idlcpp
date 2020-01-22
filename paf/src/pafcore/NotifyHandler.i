#import "Reference.i"
#import "NotifyHandlerList.i"
#import "Iterator.i"

#{
#include "Utility.h"
#}

namespace pafcore
{
	enum class PropertyChangedFlag
	{
		update, //属性值变更，如果是容器属性，则 iterator 指向变更项, 否则为null
		remove, //容器属性移除一项之前，iterator 指向即将移除的项
		add, //容器属性增加一项之后，iterator 指向刚增加的项
		reset,//容器属性多个项变换，iterator 为 null
		candidate_list //属性候选列表变更 (不是属性值变更)
	};

	override class #PAFCORE_EXPORT NotifyHandler : Reference
	{
		//override virtual void onDestroyNotifyHandlerList(NotifyHandlerList* sender);
		//override virtual void onAttachNotifySource(NotifyHandlerList* sender);
		//override virtual void onDetachNotifySource(NotifyHandlerList* sender);
	};

	override class #PAFCORE_EXPORT PropertyChangedNotifyHandler : NotifyHandler
	{
		override virtual void onPropertyChanged(Reference* sender, string_t propertyName, PropertyChangedFlag flag, Iterator* iterator);
		override virtual void onPropertyAvailabilityChanged(Reference* sender, string_t propertyName);
		override virtual void onDynamicPropertyChanged(Reference* sender, string_t propertyName, PropertyChangedFlag flag, Iterator* iterator);
		override virtual void onUpdateDynamicProperty(Reference* sender);
	};
}
