/****************************************************************************
 Author: Luma (stubma@gmail.com)
 
 https://github.com/stubma/cocos2dx-better
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/
#ifndef __CCTreeFadeIn_h__
#define __CCTreeFadeIn_h__

#include "ccTypes.h"
#include "actions/CCActionInterval.h"

NS_CC_BEGIN

/// fade in action which also fade in all descendants
class CC_DLL CCTreeFadeIn : public CCFadeIn {
private:
	/// excluded node list
	CCArray m_excludeList;
    
    /// true means children of excluded node will also be excluded
    bool m_recursivelyExclude;
	
protected:
    CCTreeFadeIn();
    
    /// fade in recursively
    void fadeInRecursively(CCNode* n, float time);
    
public:
    /** creates the action */
    static CCTreeFadeIn* create(float d);
    
    virtual void update(float time);
    virtual CCActionInterval* reverse(void);
	
	/// add excluded node
	void excludeNode(CCNode* n, bool recursively = true);
};

NS_CC_END

#endif /* defined(__CCTreeFadeIn_h__) */
