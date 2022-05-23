package main

import (
	"fmt"
	"sync"
	"time"
)

type Singleton struct {
}

var mtx sync.Mutex
var instance *Singleton

func GetInstanceWithMutex() *Singleton {
	if instance == nil {
		mtx.Lock()
		defer mtx.Unlock()
		if instance == nil {
			fmt.Println("Create single instance")
			instance = &Singleton{}
		} else {
			fmt.Println("Instance already created")
		}
	} else {
		fmt.Println("Instance already created")
	}
	return instance
}

func main() {
	for i := 0; i < 10; i++ {
		go GetInstanceWithMutex()
	}
	time.Sleep(3 * time.Millisecond)
	fmt.Println("Done!")
}
