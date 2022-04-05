package main

import (
	"encoding/json"
	"fmt"
	"io"
	"log"
	"net/http"
	"os"
)

var myLogger *log.Logger

func init() {
	file, err := os.OpenFile("out.out", os.O_CREATE|os.O_RDWR|os.O_APPEND, 0666)
	if err != nil {
		myLogger.Panic(err)
	}
	myLogger = log.New(io.MultiWriter(os.Stdout, file), "myLogger: ", log.LstdFlags)
}

type VideoInfo struct {
	Code int `json:"code"`
	Data struct {
		Bvid  string `json:"bvid"`
		Title string `json:"title"`
		Desc  string `json:"desc"`
	} `json:"data"`
}
type InfoResponse struct {
	Infos []VideoInfo
}

func main() {
	fmt.Printf("bilibili downloader ...\n\n")

	resp, err := http.Get("https://api.bilibili.com/x/web-interface/view?bvid=BV1Ff4y187q9")
	if err != nil {
		myLogger.Print(err)
	}
	respBytes, err := io.ReadAll(resp.Body)
	defer resp.Body.Close()

	var videoInfo VideoInfo

	_ = json.Unmarshal(respBytes, &videoInfo)

	fmt.Printf("%+v\n", videoInfo)
	myLogger.Print(videoInfo)
}
