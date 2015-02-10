#include <vtkXMLPolyDataReader.h>
#include <vtkSmartPointer.h>
#include <vtkPolyDataMapper.h>
#include <vtkSTLWriter.h>
#include <assert.h>

int main ( int argc, char *argv[] )
{
  // Parse command line arguments
  if(argc != 2)
    {
    std::cerr << "Usage: " << argv[0]
              << " Filename(.vtp)" << std::endl;
    return EXIT_FAILURE;
    }

  std::string filename = argv[1];

  // Read all the data from the file
  vtkSmartPointer<vtkXMLPolyDataReader> reader =
    vtkSmartPointer<vtkXMLPolyDataReader>::New();
  reader->SetFileName(filename.c_str());
  reader->Update();

  vtkSmartPointer<vtkSTLWriter> stlWriter =
    vtkSmartPointer<vtkSTLWriter>::New();

#if VTK_MAJOR_VERSION <= 5
  stlWriter->SetInputConnection(reader->GetOutputPort());
#else
  stlWriter->SetInputConnection(reader->GetOutputPort());
#endif

  stlWriter->SetFileTypeToBinary();
  stlWriter->WriteToOutputStringOn();

  stlWriter->Write();
  char* output = stlWriter->GetOutputString();
  int outLen = stlWriter->GetOutputStringLength();

  assert(output != 0);
  assert(outLen > 0);

  return EXIT_SUCCESS;
}
