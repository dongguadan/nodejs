{
  "targets": [
    {
      "target_name": "transfer",
      "sources": [ "transfer.cc" ],
      "include_dirs" : [ "<!(node -e \"require('nan')\")" ]
    }
  ]
}