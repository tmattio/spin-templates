class Tmattio{{ project_slug | camel_case }} < Formula
  VERSION = '0.1.0'
  desc '{{ project_description }}'
  homepage 'https://github.com/tmattio/{{ project_slug }}'
  url "https://github.com/tmattio/{{ project_slug }}/releases/download/v#{VERSION}/{{ project_slug }}-darwin-x64.zip"
  version VERSION

  bottle :unneeded

  test do
  end

  def install
    mv "{{ project_slug }}.exe", "{{ project_slug }}"
    bin.install '{{ project_slug }}'
  end
end
