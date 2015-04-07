{
  'targets': [
    {
      'target_name': 'srand',
      'include_dirs': [ "<!(node -e \"require('nan')\")" ],
      'sources': [ 'srand.cc' ]
    }
  ]
}
