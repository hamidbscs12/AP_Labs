/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package assembly.line.problem;

//package com.mkyong;
 
import java.io.File;
import java.util.ArrayList;
import java.util.List;
import java.util.*;
 
public class FileSearch {
 
  private String fileNameToSearch;
  private List<String> result;
static private HashMap<String,List<String>> hm=new HashMap();
    public FileSearch() {
        this.result = new ArrayList<String>();
    }
 
  public String getFileNameToSearch() {
	return fileNameToSearch;
  }
 
  public void setFileNameToSearch(String fileNameToSearch) {
	this.fileNameToSearch = fileNameToSearch;
  }
 
  public List<String> getResult() {
	return result;
  }
 
  public static void main(String[] args) {
 
	FileSearch fileSearch = new FileSearch();
        
        //try different directory and filename :)
	fileSearch.searchDirectory(new File("C:\\Users\\sahmed.seecs\\Desktop"), "sample-result-sheet.csv");
 
	int count = fileSearch.getResult().size();
	if(count ==0){
	    System.out.println("\nNo result found!");
	}else{
	    System.out.println("\nFound " + count + " result!\n");
	    for (String matched : fileSearch.getResult()){
		System.out.println("Found : " + matched);
	    }
            String tem=fileSearch.fileNameToSearch;
           hm.get(tem);
           System.out.println("index========="+hm.get(tem));
            
	}
  }
 
  public void searchDirectory(File directory, String fileNameToSearch) {
 
	setFileNameToSearch(fileNameToSearch);
 
	if (directory.isDirectory()) {
	    search(directory);
	} else {
	    System.out.println(directory.getAbsoluteFile() + " is not a directory!");
	}
 
  }
 
  private void search(File file) {
 
	if (file.isDirectory()) {
	  //System.out.println("Searching directory ... " + file.getAbsoluteFile());
 
            //do you have permission to read this directory?	
	    if (file.canRead()) {
		for (File temp : file.listFiles()) {
		    if (temp.isDirectory()) {
			search(temp);
		    } else {
			if (getFileNameToSearch().equals(temp.getName().toLowerCase())) {			
			    result.add(temp.getAbsoluteFile().toString());
                            hm.put(temp.getName(), result);//  push in HashMap
                          //  System.out.println("index========="+hm.put(temp.getName(), result));
		    }
 
		}
	    }
 
	 } else {
		System.out.println(file.getAbsoluteFile() + "Permission Denied");
	 }
      }
 
  }
 
}