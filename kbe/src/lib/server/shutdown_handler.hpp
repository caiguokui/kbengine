/*
This source file is part of KBEngine
For the latest info, see http://www.kbengine.org/

Copyright (c) 2008-2012 KBEngine.

KBEngine is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

KBEngine is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.
 
You should have received a copy of the GNU Lesser General Public License
along with KBEngine.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __SHUTDOWN_HANDLER__
#define __SHUTDOWN_HANDLER__

#include "cstdkbe/cstdkbe.hpp"
#include "cstdkbe/timer.hpp"
#include "helper/debug_helper.hpp"

namespace KBEngine { 

class ShutdownHandler 
{
public:
	ShutdownHandler():lastShutdownFailReason_("tasks"),
	shuttingdown_(false){
	}
	
	virtual ~ShutdownHandler(){}
	
	virtual void onShutdownBegin() = 0;
	virtual void onShutdown(bool first) = 0;
	virtual void onShutdownEnd() = 0;
	
	virtual bool canShutdown(){ return true; }
	
	void setShuttingdown(){ shuttingdown_ = true; }
	bool shuttingdown()const{ return shuttingdown_; }
	const std::string& lastShutdownFailReason(){ return lastShutdownFailReason_; }
protected:
	std::string lastShutdownFailReason_; // 最后一次关机失败的原因
	bool shuttingdown_;
};

}

#endif
