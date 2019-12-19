TARGET = main
SRCS = test-methods/test_methods.cpp src/Tools/StopCondition.cpp src/Tools/math.cpp src/Methods/Adam/Adam.cpp src/Methods/Adadelta/Adadelta.cpp src/Methods/Adagrad/Adagrad.cpp src/Methods/AdaMax/AdaMax.cpp src/Methods/AMSGrad/AMSGrad.cpp src/Methods/Nadam/Nadam.cpp src/Methods/bfgs/bfgs.cpp src/Methods/bfgs/bfgs2.cpp src/Methods/powell/powell.cpp src/Methods/hessian_free/hessian_free.cpp src/Methods/nesterov/nesterov.cpp src/Methods/dfp/dfp.cpp src/Methods/dfp/dfp2.cpp src/Methods/Adam/AdamW.cpp src/Methods/RmsProp/RmsProp.cpp src/Methods/powell/powell2.cpp src/Methods/powell/powell21.cpp
OBJS = $(SRCS:.cpp=.o)
CXX ?= gcc
CXXFLAGS ?= -pthread -Ofast -std=c++14 -Wall -Wextra -fmax-errors=2 -I"include"

# Поддиректории, в которых также нужно осуществить сборку:
SUBDIRS := test-methods test-NiederreiterBaseTwo

# Если в них нужно осуществлять сборку, то нужно и выполнять make clean
# Преобразуем цели, добавив суффикс, отвечающий за очистку:
CLEAN_SUFFIX := ___clean___
SUBDIRS_CLEAN := $(foreach dir,$(SUBDIRS),$(dir)$(CLEAN_SUFFIX))
EMPTY :=

.PHONY: all $(SUBDIRS) clean

all: $(TARGET) $(SUBDIRS)
$(TARGET): $(OBJS)
		$(CXX) -o $(TARGET) $(OBJS) $(CXXFLAGS)
$(SUBDIRS):
		$(MAKE) -C $@
 
.c.o:
		$(CXX) $(CXXFLAGS) -c $< -o $@

clean: $(SUBDIRS_CLEAN)
		rm -rf $(TARGET) $(OBJS)
$(SUBDIRS_CLEAN):
		$(MAKE) -C $(@:$(CLEAN_SUFFIX)=$(EMPTY)) clean