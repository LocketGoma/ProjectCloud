import unreal
import os
import sys
import csv
#import main as m
#from importlib import *
#reload(m)
#https://forums.unrealengine.com/t/reimport-datatable-csv-with-python/567768/3

project_dir = unreal.SystemLibrary.get_project_directory()
project_name = "ProjectCloud"
file_name = r"Content/GameDataTable/CLGameplayTags.csv"
dpath = r"/Game/GameBase/DataSet"

#data check
#if __name__ == '__main__':
#    print(sys.argv[0])
#    print(sys.argv[1])    
#file_name = sys.argv[1]+".csv"

#csv to Unreal DataTable
#https://wildgoosechase.tistory.com/103

class TagStruct(unreal.StructBase):
    def __init__ (self):
        self.tag = ""
        self.DevComment = ""

def reimport():
    task = unreal.AssetImportTask()
    task.filename = project_dir + file_name
    task.destination_path = dpath
    task.destination_name = "DT_CLGameplayTags"
    task.replace_existing = True
    task.automated = True
    task.save =  False
    
    #struct_name = "/Game/GameBase/DataSet/TagDataTableRow"  #임의의 BP 구조체를 생성...
    struct_name = "GameplayTags.GameplayTagTableRow"  #기 구현된 Struct 사용
    row_struct = unreal.DataTableFactory()
    row_struct.struct = unreal.load_object(None, struct_name)
    #data_Table = unreal.load_object(None, '/Game/GameBase/DataSet/DT_CLGameplayTags.DT_CLGameplayTags')
    
    if not row_struct.struct:
        raise ValueError(f"Failed to find row struct: {struct_name}")

    csv_factory = unreal.CSVImportFactory()
    if row_struct.struct :
        csv_factory.automated_import_settings.import_row_struct = row_struct.struct
        
    task.factory = csv_factory
    
    asset_tools = unreal.AssetToolsHelpers.get_asset_tools()
    asset_tools.import_asset_tasks([task])
    
reimport()
#remove temp csv